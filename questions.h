#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct QUESTION {
    std::string que;
    std::vector<std::string> ans;
    int anss;
};

class questions {
private:
    std::fstream file2;
    int c;
    QUESTION question;

public:
    void ques();
    void getQuestionAnswer(QUESTION &question);
    void writeQuestionToExam();
    void addQuestionToExam();
    void readExam() const;
};

void questions::getQuestionAnswer(QUESTION &question) {
    std::cout << "\n enter the question:";
    std::cin.ignore();
    std::getline(std::cin, question.que);

    for (int i = 0; i < 5; i++) {
        std::cout << "\n enter the " << (i + 1) << " answer:";
        std::getline(std::cin, question.ans[i]);

        std::cout << "\n Is it the correct answer? (1 for yes, 2 for no): ";
        int isCorrect;
        std::cin >> isCorrect;
        question.ans.push_back(isCorrect == 1 ? "yes" : "no");

        if (isCorrect == 1) {
            question.anss = i;
        }
    }
}

void questions::writeQuestionToExam() {
    file2.open("exam.txt", std::ios::binary | std::ios::in | std::ios::out);
    file2.seekp(0L, std::ios::beg);

    getQuestionAnswer(question);

    file2.write(reinterpret_cast<char*>(&question), sizeof(question));
    file2.close();
}

void questions::addQuestionToExam() {
    file2.open("exam.txt", std::ios::binary | std::ios::in | std::ios::out);
    file2.seekp(0L, std::ios::end);

    getQuestionAnswer(question);

    file2.write(reinterpret_cast<char*>(&question), sizeof(question));
    file2.close();
}

void questions::readExam() const {
    std::cout << "\n\t\t\t\t*********View Exam Paper*********\n";
    int coun;
    file2.open("exam.txt", std::ios::binary | std::ios::in | std::ios::out);
    file2.seekg(0L, std::ios::beg);

    while (file2.read(reinterpret_cast<char*>(&question), sizeof(question))) {
        coun = 0;
        std::cout << "\n" << question.que << "\n";

        for (int i = 0; i < 5; i++) {
            std::cout << (i + 1) << "*) " << question.ans[i] << "\n";
        }

        for (int i = 0; i < 5; i++) {
            ++coun;
            if (question.ans[i] == "yes") {
                std::cout << "\nAnswer is: " << (i + 1);
            }
        }
        std::cout << "\n\n**********\n";
    }

    file2.close();
}

void questions::ques() {
    std::cout << "\n1-To set a new exam\n2-Add a question to an existing exam\n3-View Exam Paper\nEnter: ";
    std::cin >> c;

    if (c == 1) {
        writeQuestionToExam();
    } else if (c == 2) {
        addQuestionToExam();
    } else if (c == 3) {
        readExam();
    } else {
        std::cout << "\nSee you next time! Bye!\n";
    }
}

int main() {
    questions quiz;
    quiz.ques();
    return 0;
}
