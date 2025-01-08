#include <iostream>

// ��������ڵ�ṹ
struct ListNode {
    int value;
    ListNode* next;
    ListNode(int val = 0, ListNode* nxt = nullptr) : value(val), next(nxt) {}
};

// ��ת������
ListNode* reverse_linked_list(ListNode* head) {
    ListNode* previous_node = nullptr;
    ListNode* current_node = head;
    ListNode* next_node = nullptr;

    while (current_node != nullptr) {
        // �ݴ���һ���ڵ�
        next_node = current_node->next;
        // ��ת��ǰ�ڵ��ָ��ָ��
        current_node->next = previous_node;
        // �ƶ�previous_node����ǰ�ڵ�
        previous_node = current_node;
        // �ƶ�����һ���ڵ�
        current_node = next_node;
    }

    // �����µ�ͷ���
    return previous_node;
}

// ������������ӡ�������ڲ��ԣ�
void print_linked_list(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->value << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

// �����������ڲ���
int main() {
    // ����һ������ 1 -> 2 -> 3 -> 4 -> nullptr
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));

    std::cout << "Original list: ";
    print_linked_list(head);

    // ��ת����
    head = reverse_linked_list(head);

    std::cout << "Reversed list: ";
    print_linked_list(head);

    // ע�⣺����Ϊ�˼򻯴���û���ͷŶ�̬������ڴ档
    // ʵ��ʹ��ʱӦ������ʵ��Ĵ�������ֹ�ڴ�й©��

    return 0;
}