#include <iostream>
#include <fstream>
using namespace std;

struct QUESTION {
    char que[500];
    char ans[5][100];
    int anss;
};

class questions {
private:
    fstream file2;
    int c;

public:
    void ques();
    void getQuestionAnswer(QUESTION &question);
    void writeQuestionToExam();
    void addQuestionToExam();
    void readExam();
};

void questions::getQuestionAnswer(QUESTION &question) {
    cout << "\n enter the question:";
    fflush(stdin);
    gets(question.que);

    for (int i = 0; i < 5; i++) {
        cout << "\n enter the " << (i + 1) << " answer:";
        fflush(stdin);
        gets(question.ans[i]);

        cout << "\n Is it the correct answer? (1 for yes, 2 for no): ";
        int isCorrect;
        cin >> isCorrect;
        question.ans[i] = isCorrect;

        if (isCorrect == 1) {
            question.anss = i;
        }
    }
}

void questions::writeQuestionToExam() {
    file2.open("exam.txt", ios::binary | ios::in | ios::out);
    file2.seekp(0L, ios::beg);

    QUESTION question;
    getQuestionAnswer(question);

    file2.write((char *)&question, sizeof(question));
    file2.close();
}

void questions::addQuestionToExam() {
    file2.open("exam.txt", ios::binary | ios::in | ios::out);
    file2.seekp(0L, ios::end);

    QUESTION question;
    getQuestionAnswer(question);

    file2.write((char *)&question, sizeof(question));
    file2.close();
}

void questions::readExam() {
    cout << "\n\t\t\t\t*********View Exam Paper*********\n";
    int coun;
    file2.open("exam.txt", ios::binary | ios::in | ios::out);
    file2.seekg(0L, ios::beg);

    while (file2.read((char *)&question, sizeof(question)) {
        coun = 0;
        cout << "\n" << question.que << "\n";

        for (int i = 0; i < 5; i++) {
            cout << (i + 1) << "*) " << question.ans[i] << "\n";
        }

        for (int i = 0; i < 5; i++) {
            ++coun;
            if (question.ans[i] == 1) {
                cout << "\nAnswer is: " << (i + 1);
            }
        }
        cout << "\n\n**********\n";
    }

    file2.close();
}

void questions::ques() {
    cout << "\n1-To set a new exam\n2-Add a question to an existing exam\n3-View Exam Paper\nEnter: ";
    cin >> c;

    if (c == 1) {
        writeQuestionToExam();
    } else if (c == 2) {
        addQuestionToExam();
    } else if (c == 3) {
        readExam();
    } else {
        cout << "\nSee you next time! Bye!\n";
    }
}

int main() {
    questions quiz;
    quiz.ques();
    return 0;
}
