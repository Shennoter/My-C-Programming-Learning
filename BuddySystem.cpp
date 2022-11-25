#include<iostream>
#define LISTNUM 10 // �ڴ��СsizeK

class BuddySystem {
private:
    struct Block {
        int id;          //���������
        int sizeK;       //�����Ĵ�С����2������ʽ2^sizeK
        int startAddr;   //�����Ŀ�ʼλ��
        bool status;     //������״̬��trueΪ���У�falseΪ��ռ��
        int pid;         //����÷�����ռ�ã�����ռ�ý��̵�id; ����Ϊ - 1
        struct Block* prev;  //ָ��ǰ��һ���ڴ����
        struct Block* next;   //ָ�����һ���ڴ����
    };
    struct PCB {
        int pid;            //���̵����
        int neededMem;      //��Ҫ���ڴ������С
        int status;         //1: �ڴ����ɹ���-1������ʧ��
        int blockID;        //�������ɹ�������ռ�÷�����id,����Ϊ - 1
        struct PCB* next;   //ָ����һ��PCB
    };

    int id = 1;
    int startAddr = 0;
    PCB* pcbHead = new PCB; // ��������
    Block* blockList[LISTNUM]; // ��ͬ��С�����ĵ�������
    Block* mainHead = new Block; // �ڴ��������

    void traverseList(int); // ��������
    void memCollect(); // �ڴ����
    Block* splitBlock(Block*, int); // �ָ������������һ������������1. ��Ҫ�и�ķ��� 2. Ŀ���С
    Block* findBlock(int, int, bool); // Ѱ�ҿ��õķ�����������1.Ŀ�������С 2.������С���ݹ鴫���ã� 3.�Ƿ��и�
    void updateMain(int, Block*); // �����������и��������1.Ҫ�и�ķ�����id 2.��Ҫ���Ƶķ���
    void updateMain(Block*); // �������������и����������Ҫ���Ƶķ���

public:
    BuddySystem();
    void allocate();
    ~BuddySystem();
};

void BuddySystem::traverseList(int flag) {
    switch (flag) { // 1Ϊ��ӡ��������2Ϊֻ��ӡ��������
    case 1: {
        std::cout << "\nPCB����\n";
        std::cout << "PID\t" << "��Ҫ�ڴ�\t" << "״̬\t" << "����ID\n";
        PCB* pNode = pcbHead->next;
        while (pNode) {
            std::cout << pNode->pid << '\t' << pNode->neededMem << "\t\t" << pNode->status << '\t' << pNode->blockID << '\n';
            pNode = pNode->next;
        }
    }
    case 2: {
        std::cout << "\n��������\n";
        std::cout << "������С\t" << "ID\t" << "��ʼ��ַ\t" << "״̬\t" << "PID\n";
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
    std::cout << "��ʼ����......\n";
    Block* fNode = mainHead->next;
    int buddyAddr = 0;
    while (mainHead->next->next) {
        Block* buf = fNode->next->next;
        int temp = pow(2, fNode->sizeK + 1);
        if (fNode->startAddr % temp == 0) { // �����������ַ
            buddyAddr = fNode->startAddr + pow(2, fNode->sizeK);
        }
        else {
            buddyAddr = fNode->startAddr - pow(2, fNode->sizeK);
        }
        if (fNode->sizeK == fNode->next->sizeK && fNode->next->startAddr == buddyAddr) {
            std::cout << "�Ѻϲ�����" << fNode->id << "�ͷ���" << fNode->next->id << '\n';
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
    std::cout << "�������\n";
}

BuddySystem::Block* BuddySystem::splitBlock(Block* block, int targetSizeK) {
    Block* prev = block->prev;
    Block* next = block->next;
    int newK = block->sizeK - 1;
    Block* buf = blockList[newK - 1]; // ��ȡ���һ��Ԫ��
    while (buf->next) {
        buf = buf->next;
    }
    // �ָ��ĵ�һ������
    Block* p1 = new Block;
    p1->id = id++;
    p1->sizeK = newK;
    p1->startAddr = block->startAddr;
    p1->status = true;
    p1->pid = -1;
    // �ָ��ĵڶ�������
    Block* p2 = new Block;
    p2->id = id++;
    p2->sizeK = newK;
    p2->startAddr = p1->startAddr + pow(2, newK);
    p2->status = true;
    p2->pid = -1;
    // ����
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
    if (sizeK > LISTNUM) { // ������������Ҳ����ɷ�������
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
        // ���û�ҵ���������ϲ�Ѱ��
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
        // ���û�ҵ���������ϲ�Ѱ��
        return findBlock(targetSizeK, sizeK + 1, true);
    }
}

void BuddySystem::updateMain(int target, Block* block) {
    Block* node = mainHead->next;
    while (node) {
        if (node->id == target) {
            Block* p1 = new Block;
            // ��������
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
            // ����
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
    std::cout << "���������ʧ��\n";
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
    std::cout << "���������ʧ��\n";
}

BuddySystem::BuddySystem() { // ���캯��
    srand((unsigned)time(NULL));
    // ��ʼ��PCB����
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
    // ��ʼ�����з�������
    for (int i = 0; i < LISTNUM; i++) {
        Block* head = new Block;
        head->next = NULL;
        blockList[i] = head;
    }
    Block* p = new Block; // ��ʼ����
    p->id = 0;
    p->sizeK = 10;
    p->startAddr = 0;
    p->status = true;
    p->pid = -1;
    blockList[LISTNUM - 1]->next = p;
    p->prev = blockList[LISTNUM - 1];
    p->next = NULL;
    // ��ʼ��������
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
            std::cout << "������Ҫ�ڴ治����\n";
            pNode = pNode->next;
            continue;
        }
        Block* fNode = findBlock(sizeK, sizeK, false);
        if (!fNode) {
            std::cout << "����" << pNode->pid << "����ʧ�ܣ�\n";
            pNode = pNode->next;
            continue;
        }
        if (fNode->status) { // ������ҵ�
            fNode->status = false;
            fNode->pid = pNode->pid;
            pNode->blockID = fNode->id;
            pNode->status = 1;
            updateMain(fNode);
            std::cout << "������" << pNode->pid << "���䵽����" << fNode->id << '\n';
            traverseList(1);
        }
        else {
            std::cout << "����" << pNode->pid << "����ʧ�ܣ�\n";
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