#include <iostream> // Для ввода/вывода
#include <vector> // Динамический массив
#include <string> // Переменная строка
#include <fstream> // Библиотека с набором классов, методов и функций которые могут представлять собой для чтения/записи данных из/файл и т.д
using namespace std;

// Функция для отображения меню
void showMenu() {
    cout << "\nМеню задач:\n";
    cout << "1. Добавить задачу\n";
    cout << "2. Показать все задачи\n";
    cout << "3. Удалить задачу\n";
    cout << "4. Сохранить задачи в файл\n";
    cout << "5. Загрузить задачи из файла\n";
    cout << "6. Выйти\n";
    cout << "Выберите опцию: ";
}

// Функция для отображения всех задач
void showTasks(const vector<string>& tasks) {
    if (tasks.empty()) {
        cout << "Список задач пуст.\n";
        return;
    }
    cout << "\nВаши задачи:\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << tasks[i] << endl;
    }
}

// Функция для удаления задачи
void deleteTask(vector<string>& tasks) {
    if (tasks.empty()) {
        cout << "Нет задач для удаления.\n";
        return;
    }
    showTasks(tasks);
    cout << "Введите номер задачи для удаления: ";
    int index;
    cin >> index;

    if (index < 1 || index > tasks.size()) {
        cout << "Неверный номер задачи.\n";
        return;
    }

    tasks.erase(tasks.begin() + (index - 1));
    cout << "Задача удалена.\n";
}

// Функция для сохранения задач в файл
void saveTasksToFile(const vector<string>& tasks, const string& filename) {
    ofstream outFile(filename);
    if (!outFile) {
        cout << "Ошибка при сохранении в файл.\n";
        return;
    }

    for (const auto& task : tasks) {
        outFile << task << endl;
    }

    cout << "Задачи сохранены в файл \"" << filename << "\".\n";
}

// Функция для загрузки задач из файла
void loadTasksFromFile(vector<string>& tasks, const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cout << "Ошибка при загрузке из файла.\n";
        return;
    }

    tasks.clear();
    string task;
    while (getline(inFile, task)) {
        tasks.push_back(task);
    }

    cout << "Задачи загружены из файла \"" << filename << "\".\n";
}

int main() {
    setlocale(LC_ALL, "Russian");
    vector<string> tasks; // Хранилище задач
    string filename = "tasks.txt"; // Имя файла для сохранения/загрузки

    while (true) {
        showMenu();

        int choice;
        cin >> choice;
        cin.ignore(); // Очищаем буфер после ввода числа

        if (choice == 1) {
            cout << "Введите задачу: ";
            string task;
            getline(cin, task);
            tasks.push_back(task);
            cout << "Задача добавлена.\n";
        }
        else if (choice == 2) {
            showTasks(tasks);
        }
        else if (choice == 3) {
            deleteTask(tasks);
        }
        else if (choice == 4) {
            saveTasksToFile(tasks, filename);
        }
        else if (choice == 5) {
            loadTasksFromFile(tasks, filename);
        }
        else if (choice == 6) {
            cout << "Выход из программы. До свидания!\n";
            break;
        }
        else {
            cout << "Неверный выбор. Попробуйте ещё раз.\n";
        }
    }

    return 0;
}
