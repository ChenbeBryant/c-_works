#include <iostream>

// 定义链表节点结构
struct ListNode {
    int value;
    ListNode* next;
    ListNode(int val = 0, ListNode* nxt = nullptr) : value(val), next(nxt) {}
};

// 翻转链表函数
ListNode* reverse_linked_list(ListNode* head) {
    ListNode* previous_node = nullptr;
    ListNode* current_node = head;
    ListNode* next_node = nullptr;

    while (current_node != nullptr) {
        // 暂存下一个节点
        next_node = current_node->next;
        // 反转当前节点的指针指向
        current_node->next = previous_node;
        // 移动previous_node到当前节点
        previous_node = current_node;
        // 移动到下一个节点
        current_node = next_node;
    }

    // 返回新的头结点
    return previous_node;
}

// 辅助函数：打印链表（用于测试）
void print_linked_list(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->value << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

// 主函数，用于测试
int main() {
    // 创建一个链表 1 -> 2 -> 3 -> 4 -> nullptr
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));

    std::cout << "Original list: ";
    print_linked_list(head);

    // 翻转链表
    head = reverse_linked_list(head);

    std::cout << "Reversed list: ";
    print_linked_list(head);

    // 注意：这里为了简化代码没有释放动态分配的内存。
    // 实际使用时应该添加适当的代码来防止内存泄漏。

    return 0;
}