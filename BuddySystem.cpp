#include<iostream>
#define LISTNUM 10 // 内存大小sizeK

class BuddySystem {
private:
    struct Block {
        int id;          //分区的序号
        int sizeK;       //分区的大小，以2的幂形式2^sizeK
        int startAddr;   //分区的开始位置
        bool status;     //分区的状态：true为空闲，false为被占用
        int pid;         //如果该分区被占用，则存放占用进程的id; 否则为 - 1
        struct Block* prev;  //指向前面一块内存分区
        struct Block* next;   //指向后面一块内存分区
    };
    struct PCB {
        int pid;            //进程的序号
        int neededMem;      //需要的内存分区大小
        int status;         //1: 内存分配成功；-1：分配失败
        int blockID;        //如果分配成功，保存占用分区的id,否则为 - 1
        struct PCB* next;   //指向下一个PCB
    };

    int id = 1;
    int startAddr = 0;
    PCB* pcbHead = new PCB; // 进程链表
    Block* blockList[LISTNUM]; // 不同大小分区的单独链表
    Block* mainHead = new Block; // 内存分区链表

    void traverseList(int); // 遍历链表
    void memCollect(); // 内存回收
    Block* splitBlock(Block*, int); // 分割分区并加入下一条链表。参数：1. 需要切割的分区 2. 目标大小
    Block* findBlock(int, int, bool); // 寻找可用的分区。参数：1.目标分区大小 2.分区大小（递归传参用） 3.是否切割
    void updateMain(int, Block*); // 更新主链表（切割）。参数：1.要切割的分区的id 2.需要复制的分区
    void updateMain(Block*); // 更新主链表（不切割）。参数：需要复制的分区

public:
    BuddySystem();
    void allocate();
    ~BuddySystem();
};

void BuddySystem::traverseList(int flag) {
    switch (flag) { // 1为打印两个链表，2为只打印分区链表
    case 1: {
        std::cout << "\nPCB链表\n";
        std::cout << "PID\t" << "需要内存\t" << "状态\t" << "分区ID\n";
        PCB* pNode = pcbHead->next;
        while (pNode) {
            std::cout << pNode->pid << '\t' << pNode->neededMem << "\t\t" << pNode->status << '\t' << pNode->blockID << '\n';
            pNode = pNode->next;
        }
    }
    case 2: {
        std::cout << "\n分区链表\n";
        std::cout << "分区大小\t" << "ID\t" << "开始地址\t" << "状态\t" << "PID\n";
        Block* mainNode = mainHead->next;
        while (mainNode) {
            std::cout << pow(2, mainNode->sizeK) << "\t\t" << mainNode->id << '\t' << mainNode->startAddr << "\t\t" << std::boolalpha << mainNode->status << '\t' << mainNode->pid << '\n';
            mainNode = mainNode->next;
        }
        std::cout << '\n';
        break;
    }
    }
}

void BuddySystem::memCollect() {
    std::cout << "开始回收......\n";
    Block* fNode = mainHead->next;
    int buddyAddr = 0;
    while (mainHead->next->next) {
        Block* buf = fNode->next->next;
        int temp = pow(2, fNode->sizeK + 1);
        if (fNode->startAddr % temp == 0) { // 计算伙伴分区地址
            buddyAddr = fNode->startAddr + pow(2, fNode->sizeK);
        }
        else {
            buddyAddr = fNode->startAddr - pow(2, fNode->sizeK);
        }
        if (fNode->sizeK == fNode->next->sizeK && fNode->next->startAddr == buddyAddr) {
            std::cout << "已合并分区" << fNode->id << "和分区" << fNode->next->id << '\n';
            fNode->sizeK += 1;
            delete fNode->next;
            if (buf) {
                fNode->next = buf;
                traverseList(2);
            }
            else {
                fNode->next = NULL;
                fNode = mainHead->next;
                traverseList(2);
            }
        }
        else {
            fNode = fNode->next;
        }
        if (!fNode->next) {
            fNode = mainHead->next;
        }
    }
    std::cout << "回收完毕\n";
}

BuddySystem::Block* BuddySystem::splitBlock(Block* block, int targetSizeK) {
    Block* prev = block->prev;
    Block* next = block->next;
    int newK = block->sizeK - 1;
    Block* buf = blockList[newK - 1]; // 获取最后一个元素
    while (buf->next) {
        buf = buf->next;
    }
    // 分割后的第一个区块
    Block* p1 = new Block;
    p1->id = id++;
    p1->sizeK = newK;
    p1->startAddr = block->startAddr;
    p1->status = true;
    p1->pid = -1;
    // 分割后的第二个区块
    Block* p2 = new Block;
    p2->id = id++;
    p2->sizeK = newK;
    p2->startAddr = p1->startAddr + pow(2, newK);
    p2->status = true;
    p2->pid = -1;
    // 连接
    prev->next = next;
    buf->next = p1;
    p1->prev = buf;
    p1->next = p2;
    p2->prev = p1;
    p2->next = NULL;
    updateMain(block->id, p1);
    delete block;
    if (p2->sizeK != targetSizeK) {
        return splitBlock(p2, targetSizeK);
    }
    else return p1;
}

BuddySystem::Block* BuddySystem::findBlock(int targetSizeK, int sizeK, bool split) {
    if (sizeK > LISTNUM) { // 如果所有链表都找不到可分配区块
        return NULL;
    }
    Block* fNode = blockList[sizeK - 1]->next;
    if (!split) {
        if (fNode) {
            while (fNode) {
                if (fNode->status) return fNode;
                else {
                    fNode = fNode->next;
                }
            }
        }
        // 如果没找到则继续向上层寻找
        return findBlock(targetSizeK, sizeK + 1, true);
    }
    else {
        if (fNode) {
            while (fNode) {
                if (fNode->status) return splitBlock(fNode, targetSizeK);
                else {
                    fNode = fNode->next;
                }
            }
        }
        // 如果没找到则继续向上层寻找
        return findBlock(targetSizeK, sizeK + 1, true);
    }
}

void BuddySystem::updateMain(int target, Block* block) {
    Block* node = mainHead->next;
    while (node) {
        if (node->id == target) {
            Block* p1 = new Block;
            // 复制区块
            p1->id = block->id;
            p1->sizeK = block->sizeK;
            p1->startAddr = block->startAddr;
            p1->status = block->status;
            p1->pid = block->pid;
            Block* p2 = new Block;
            Block* block2 = block->next;
            p2->id = block2->id;
            p2->sizeK = block2->sizeK;
            p2->startAddr = block2->startAddr;
            p2->status = block2->status;
            p2->pid = block2->pid;
            // 连接
            node->prev->next = p1;
            p1->prev = node->prev;
            p1->next = p2;
            p2->prev = p1;
            if (node->next) {
                p2->next = node->next;
                node->next->prev = p2;
            }
            else {
                p2->next = NULL;
            }
            delete node;
            return;
        }
        else {
            node = node->next;
        }
    }
    std::cout << "主链表更新失败\n";
}

void BuddySystem::updateMain(Block* block) {
    Block* node = mainHead->next;
    while (node) {
        if (node->id == block->id) {
            node->sizeK = block->sizeK;
            node->startAddr = block->startAddr;
            node->status = block->status;
            node->pid = block->pid;
            return;
        }
        else {
            node = node->next;
        }
    }
    std::cout << "主链表更新失败\n";
}

BuddySystem::BuddySystem() { // 构造函数
    srand((unsigned)time(NULL));
    // 初始化PCB链表
    PCB* pre = pcbHead;
    for (int i = 0; i < 8; i++) {
        PCB* p = new PCB;
        p->pid = i;
        p->neededMem = pow(2, (rand() % 6 + 3)); // 2^[3, 8]
        p->status = 0;
        p->blockID = -1;
        pre->next = p;
        pre = p;
        p->next = NULL;
    }
    //PCB* p1 = new PCB;
    //p1->pid = 0;
    //p1->neededMem = pow(2, 7);
    //p1->status = 0;
    //p1->blockID = -1;
    //PCB* p2 = new PCB;
    //p2->pid = 0;
    //p2->neededMem = pow(2, 4);
    //p2->status = 0;
    //p2->blockID = -1;
    //PCB* p3 = new PCB;
    //p3->pid = 0;
    //p3->neededMem = pow(2, 8);
    //p3->status = 0;
    //p3->blockID = -1;
    //pcbHead->next = p1;
    //p1->next = p2;
    //p2->next = p3;
    //p3->next = NULL;
    // 初始化空闲分区链表
    for (int i = 0; i < LISTNUM; i++) {
        Block* head = new Block;
        head->next = NULL;
        blockList[i] = head;
    }
    Block* p = new Block; // 初始区块
    p->id = 0;
    p->sizeK = 10;
    p->startAddr = 0;
    p->status = true;
    p->pid = -1;
    blockList[LISTNUM - 1]->next = p;
    p->prev = blockList[LISTNUM - 1];
    p->next = NULL;
    // 初始化主链表
    Block* pMain = new Block;
    pMain->id = 0;
    pMain->sizeK = 10;
    pMain->startAddr = 0;
    pMain->status = true;
    pMain->pid = -1;
    pMain->prev = mainHead;
    pMain->next = NULL;
    mainHead->next = pMain;
    traverseList(1);
}

void BuddySystem::allocate() {
    PCB* pNode = pcbHead->next;
    while (pNode) {
        int sizeK = -1;
        for (int i = 0; i < LISTNUM; i++) {
            if (pow(2, i) < pNode->neededMem && pNode->neededMem <= pow(2, i + 1)) {
                sizeK = i + 1;
                break;
            }
        }
        if (sizeK < 0 || sizeK > LISTNUM) {
            std::cout << "进程需要内存不合理\n";
            pNode = pNode->next;
            continue;
        }
        Block* fNode = findBlock(sizeK, sizeK, false);
        if (!fNode) {
            std::cout << "进程" << pNode->pid << "分配失败！\n";
            pNode = pNode->next;
            continue;
        }
        if (fNode->status) { // 如果能找到
            fNode->status = false;
            fNode->pid = pNode->pid;
            pNode->blockID = fNode->id;
            pNode->status = 1;
            updateMain(fNode);
            std::cout << "将进程" << pNode->pid << "分配到区块" << fNode->id << '\n';
            traverseList(1);
        }
        else {
            std::cout << "进程" << pNode->pid << "分配失败！\n";
        }
        pNode = pNode->next;
    }
}

BuddySystem::~BuddySystem() {
    memCollect();
}

int main() {
    BuddySystem buddySys = BuddySystem();
    buddySys.allocate();
	return 0;
}