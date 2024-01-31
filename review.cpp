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
        cout << "할 일 내용:";
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
        cout << "완료된 번호 입력:";
        cin >> doneItemNumber;

        if (doneItemNumber < 0 || 100 < doneItemNumber) {
            cout << "없는 투두리스트 번호입니다." << endl;
            return;
        }

        if (this->item[doneItemNumber].getIsCompleted()) {
            cout << "이미 완료된 일입니다." << endl;
            return;
        }

        this->item[doneItemNumber].setComplete();
        cout << "수정 되었습니다." << endl;
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
                cout << i + 1 << this->item[i].getContent() << "완료!" << endl;
        }
    }
};

class UI {

public:
    void showChoice() {
        cout << "투두 리스트 " << endl;
        cout << "1. 할 일 추가하기" << endl;
        cout << "2. 할 일 보기" << endl;
        cout << "3. 할 일 완료하기" << endl;
        cout << "4. 완료된 일 보기" << endl;
        cout << "5. 프로그램 종료" << endl;
    }

};

int main() {
    UI todoListSystem;
    TodoList todoList;
    while (true) {
        todoListSystem.showChoice();
        cout << "번호 입력:";
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
            cout << "번호 입력 오류" << endl;
        }
    }

    return 0;
}
