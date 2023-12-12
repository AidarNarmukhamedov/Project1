#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct Product {
	string Name;
	double price;
	int quantity;
};

void addProductToFile(const Product& product) {
    ofstream outFile("products.txt");
    if (outFile.is_open()) {
        outFile << product.Name << "," << product.price << "," << product.quantity <<endl;
        outFile.close();
        cout << "Продукт успешко добавлен." << endl;
    }
    else {
        cerr << "Не удалось открыть файл для записи." << endl;
    }
}

void searchProductByName(const string& name) {
    ifstream inFile("products.txt");
    if (inFile.is_open()) {
        string line;
        bool found = false;
        while (getline(inFile, line)) {
            size_t pos = line.find(',');
            string Name = line.substr(0, pos);
            if (Name == name) {
                cout << "Найден продукт: " << line <<endl;
                found = true;
                break;
            }
        }
        inFile.close();
        if (!found) {
            cout << "Продукт с таким названием не найден." <<endl;
        }
    }
    else {
        cerr << "Не удалось открыть файл для чтения." <<endl;
    }
}
void sortProductsByQuantity() {
    ifstream inFile("products.txt");
    if (inFile.is_open()) {
        string lines[50];
        int count = 0;
        string line;
        while (getline(inFile, line)) {
            lines[count] = line;
            count++;
        }
        inFile.close();
        for (int i = 0; i < count - 1; i++) {
            for (int j = 0; j < count - i - 1; j++) {
                size_t pos1 = lines[j].find_last_of(',');
                size_t pos2 = lines[j + 1].find_last_of(',');
                int quantity1 = stoi(lines[j].substr(pos1 + 1));
                double quantity2 = stoi(lines[j + 1].substr(pos2 + 1));
                if (quantity1 < quantity2) {
                    swap(lines[j], lines[j + 1]);
                }
            }
        }
        ofstream outFile("products.txt");
        if (outFile.is_open()) {
            for (int i = 0; i < count; i++) {
                outFile << lines[i] <<endl;
            }
            outFile.close();
            cout << "Продукты отсортированы по количетсву" <<endl;
        }
        else {
            cerr << "Не удалось открыть файл для записи." <<endl;
        }
    }
    else {
        cerr << "Не удалось открыть файл для чтения." <<endl;
    }
}

void searchProductsByPrice(const string& cena) {
    ifstream inFile("products.txt");
    if (inFile.is_open()) {
        string line;
        bool found = false;
        while (getline(inFile, line)) {
            size_t pos = line.find(',');
            string price = line.substr(pos + 1);
            if (price <= cena) {
                cout << "Найден продукт: " << line << endl;
                found = true;
            }
        }
        inFile.close();
        if (!found) {
            cout << "Продукты дешевле этой цены не найдены." << endl;
        }
    }
    else {
        cerr << "Не удалось открыть файл для чтения." << endl;
    }
}
int main() {
    int choice;
    string name;
    setlocale(LC_ALL, "Russian");
    do {
        cout << "Меню:" << std::endl;
        cout << "1. Добавить продукт" << endl;
        cout << "2. Поиск продукта по названию" << std::endl;
        cout << "3. Сортировать продукты по количеству" << endl;
        cout << "4. Поиск всех продуктов по цене" << endl;
        cout << "0. Выйти" << endl;
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            cin.ignore();
            string Name;
            double price;
            int quantity;
            cout << "Введите название продукта ";
            getline(cin, Name);
            if (Name.empty()) {
                cout << "Ввод прерван." << endl;
                break;
            }
            cout << "Введите цену продукта ";
            cin >> price;
            cout << "Введите количество этого продукта ";
            cin >> quantity;
            Product newProduct = { Name, price, quantity };
            addProductToFile(newProduct);
            break;
        }
        case 2: {
            cin.ignore();
            cout << "Введите название продукта для поиска: ";
            getline(cin, name);
            searchProductByName(name);
            break;
        }
        case 3: {
            sortProductsByQuantity();
            break;
        }
        case 4: {
            string cena;
            cout << "Введите цену: ";
            cin >> cena;
            searchProductsByPrice(cena);
            break;
        }
        case 0: {
            cout << "Программа завершена." << endl;
            break;
        }
        default: {
            cout << "Неверный выбор. Попробуйте снова." << endl;
            break;
        }
        }
    } while (choice != 0);

    return 0;
}

