#include "test_runner.h"

#include <vector>
#include <string>
#include <algorithm>

template <typename T>
class LinkedList {
public:
    struct Node {
        T value;
        Node* next = nullptr;
    };

    ~LinkedList() {
        while (head!=nullptr){
            Node* next = head->next;
            PopFront();
            head=next;
        }
    }

    void PushFront(const T& value) {
        Node *temp=new Node;
        temp->value=value;
        temp->next= head;
        head=temp;
    }

    void InsertAfter(Node* node, const T& value) {
        if (node != nullptr){
            auto temp2 = new Node();
            temp2->next = node->next;
            temp2->value = value;
            node->next = temp2;
        }
        else
            PushFront(value);

    }

    void RemoveAfter(Node* node) {
        if (node== nullptr) {
            PopFront();
            return;
        }
        if (node->next!= nullptr) {
            auto temp = node->next;
            auto temp2 = temp->next;
            node->next = temp2;
            delete temp;
        }
    }

    void PopFront() {
        if (head != nullptr){
            auto temp = head;
            head=head->next;
            delete temp;
        }
    }

    Node* GetHead() {
        return head;
    }

    const Node* GetHead() const {
        return head;
    }

private:
    Node* head = nullptr;
};

template <typename T>
std::vector<T> ToVector(const LinkedList<T>& list) {
    std::vector<T> result;
    for (auto node = list.GetHead(); node; node = node->next) {
        result.push_back(node->value);
    }
    return result;
}

void TestPushFront() {
    LinkedList<int> list;

    list.PushFront(1);
    ASSERT_EQUAL(list.GetHead()->value, 1);
    list.PushFront(2);
    ASSERT_EQUAL(list.GetHead()->value, 2);
    list.PushFront(3);
    ASSERT_EQUAL(list.GetHead()->value, 3);

    const std::vector<int> expected = {3, 2, 1};
    ASSERT_EQUAL(ToVector(list), expected);
}

void TestInsertAfter() {
    LinkedList<std::string> list;

    list.PushFront("a");
    auto head = list.GetHead();
    ASSERT(head);
    ASSERT_EQUAL(head->value, "a");

    list.InsertAfter(head, "b");
    const std::vector<std::string> expected1 = {"a", "b"};
    ASSERT_EQUAL(ToVector(list), expected1);

    list.InsertAfter(head, "c");
    const std::vector<std::string> expected2 = {"a", "c", "b"};
    ASSERT_EQUAL(ToVector(list), expected2);
}

void TestRemoveAfter() {
    LinkedList<int> list;
    for (int i = 1; i <= 5; ++i) {
        list.PushFront(i);
    }

    const std::vector<int> expected = {5, 4, 3, 2, 1};
    ASSERT_EQUAL(ToVector(list), expected);

    auto next_to_head = list.GetHead()->next;
    list.RemoveAfter(next_to_head); // удаляем 3
    list.RemoveAfter(next_to_head); // удаляем 2

    const std::vector<int> expected1 = {5, 4, 1};
    ASSERT_EQUAL(ToVector(list), expected1);

    while (list.GetHead()->next) {
        list.RemoveAfter(list.GetHead());
    }
    ASSERT_EQUAL(list.GetHead()->value, 5);
}

void TestPopFront() {
    LinkedList<int> list;

    for (int i = 1; i <= 5; ++i) {
        list.PushFront(i);
    }
    for (int i = 1; i <= 5; ++i) {
        list.PopFront();
    }
    ASSERT(list.GetHead() == nullptr);
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestPushFront);
    RUN_TEST(tr, TestInsertAfter);
    RUN_TEST(tr, TestRemoveAfter);
    RUN_TEST(tr, TestPopFront);

    return 0;
}
