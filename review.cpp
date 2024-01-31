#include<iostream>
#include<string>
using namespace std;
// class todoItem
// class todoList
class TodoItem {
private:
    string content;
    bool isCompleted;
public:
    TodoItem() :content(content), isCompleted(false) {}

    void setContent() {
        string todo;
        cout << "�� �� ����:";
        cin >> todo;
        this->content = todo;
    }

    string getContent() {
        return this->content;
    }

    void setComplete() {
        this->isCompleted = true;
    }

    bool getIsCompleted() {
        return this->isCompleted;
    }
};

class TodoList {
private:
    TodoItem item[100];
    int itemCount;
public:
    TodoList() :itemCount(0) {}
    void addItem() {
        TodoItem temp;
        temp.setContent();
        item[this->itemCount++] = temp;
    }

    void makeDone() {
        this->showTodo();
        int doneItemNumber;
        cout << "�Ϸ�� ��ȣ �Է�:";
        cin >> doneItemNumber;

        if (doneItemNumber < 0 || 100 < doneItemNumber) {
            cout << "���� ���θ���Ʈ ��ȣ�Դϴ�." << endl;
            return;
        }

        if (this->item[doneItemNumber].getIsCompleted()) {
            cout << "�̹� �Ϸ�� ���Դϴ�." << endl;
            return;
        }

        this->item[doneItemNumber].setComplete();
        cout << "���� �Ǿ����ϴ�." << endl;
    }


    void showTodo() {
        for (int i = 0; i < this->itemCount; i++) {
            if (!this->item[i].getIsCompleted())
                cout << i + 1 << this->item[i].getContent() << endl;
        }
    }

    void showDone() {
        for (int i = 0; i < this->itemCount; i++) {
            if (this->item[i].getIsCompleted())
                cout << i + 1 << this->item[i].getContent() << "�Ϸ�!" << endl;
        }
    }
};

class UI {

public:
    void showChoice() {
        cout << "���� ����Ʈ " << endl;
        cout << "1. �� �� �߰��ϱ�" << endl;
        cout << "2. �� �� ����" << endl;
        cout << "3. �� �� �Ϸ��ϱ�" << endl;
        cout << "4. �Ϸ�� �� ����" << endl;
        cout << "5. ���α׷� ����" << endl;
    }

};

int main() {
    UI todoListSystem;
    TodoList todoList;
    while (true) {
        todoListSystem.showChoice();
        cout << "��ȣ �Է�:";
        int systemNumber;
        cin >> systemNumber;
        switch (systemNumber) {
        case 1:
            todoList.addItem();
            break;
        case 2:
            todoList.showTodo();
            break;
        case 3:
            todoList.makeDone();
            break;
        case 4:
            todoList.showDone();
            break;
        case 5:
            return 1;
        default:
            cout << "��ȣ �Է� ����" << endl;
        }
    }

    return 0;
}
