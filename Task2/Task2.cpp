#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

struct Matrix3x3
{
    int size = 3;
    int count = 9;
    int data[9];
    Matrix3x3() {}
    int element(const int i, const int j) const
    {
        return data[i * size + j];
    }
    void setElement(const int i, const int j, const int value)
    {
        data[i * size + j] = value;
    }
    void fillRandomElements(const int minVal, const int maxVal)
    {
        for(int i = 0; i < count; i++)
            data[i] = rand()%(maxVal - minVal) + minVal;
    }
    int sumPrincipalDiag() const
    {
        int res = 0;
        for (int i = 0; i < count; i += 4)
            res += data[i];
        return res;
    }
    int sumSecondaryDiag() const
    {
        int res = 0;
        for (int i = size - 1; i < count - 1; i+= size - 1)
            res += data[i];
        return res;
    }
    int productPrincipalDiag() const
    {
        int res = 1;
        for (int i = 0; i < count; i += size + 1)
            res *= data[i];
        return res;
    }
    int productSecondaryDiag() const
    {
        int res = 1;
        for (int i = size - 1; i < count - 1; i += size - 1)
            res *= data[i];
        return res;
    }
    int sumRow(const int iRow) const
    {
        int res = 0;
        for (int i = 0; i < size; i++)
            res += data[iRow * size + i];
        return res;
    }
    int minColumn(const int iCol) const
    {
        int min = data[iCol];
        for (int i = 1; i < size; i++)
            if (data[i * size + iCol] < min) min = data[i * size + iCol];
        return min;
    }
    int maxColumn(const int iCol) const
    {
        int max = data[iCol];
        for (int i = 1; i < size; i++)
            if (data[i * size + iCol] > max) max = data[i * size + iCol];
        return max;
    }

    void print()
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
                cout << data[i*size + j] << " ";
            cout << endl;
        }
    }
};

struct MatrixXnX
{
    int size;
    int** data;
    int count;
    MatrixXnX(const int iDim) : size(iDim), data(new int*[iDim]), count(iDim* iDim)
    {
        for (int i = 0; i < iDim; i++)
        {
            data[i] = new int[iDim];
            for (int j = 0; j < iDim; j++)
                data[i][j] = 0;
        }
    }
    ~MatrixXnX()
    {
        for (int i = 0; i < size; i++)
        {
            delete[] data[i];
        }
        delete[] data;
    }
    int element(const int i, const int j) const
    {
        return data[i][j];
    }
    void setElement(const int i, const int j, const int value)
    {
        data[i][j] = value;
    }
    void fillRandomElements(const int minVal, const int maxVal)
    {
        for (int i = 0; i < size; i++)
            for(int j = 0; j < size; j++)
                data[i][j] = rand() % (maxVal - minVal) + minVal;
    }
    int sumPrincipalDiag() const
    {
        int res = 0;
        for (int i = 0; i < size; i ++)
            res += data[i][i];
        return res;
    }
    int sumSecondaryDiag() const
    {
        int res = 0;
        for (int i = 0; i < size; i++)
            res += data[i][size - i - 1];
        return res;
    }
    int productPrincipalDiag() const
    {
        int res = 1;
        for (int i = 0; i < size; i++)
            res *= data[i][i];
        return res;
    }
    int productSecondaryDiag() const
    {
        int res = 1;
        for (int i = 0; i < size; i++)
            res *= data[i][size - i - 1];
        return res;
    }
    int sumRow(const int iRow) const
    {
        int res = 0;
        for (int i = 0; i < size; i++)
            res += data[iRow][i];
        return res;
    }
    int minColumn(const int iCol) const
    {
        int min = data[0][iCol];
        for (int i = 1; i < size; i++)
            if (data[i][iCol] < min) min = data[i][iCol];
        return min;
    }
    int maxColumn(const int iCol) const
    {
        int max = data[0][iCol];
        for (int i = 1; i < size; i++)
            if (data[i][iCol] > max) max = data[i][iCol];
        return max;
    }
    void print()
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
                cout << data[i][j] << " ";
            cout << endl;
        }
    }
};

struct SLListNode
{
    int value;
    SLListNode* next = nullptr;
    SLListNode(int value) : value(value) {}
};

struct SingleLinkedList
{
    int count = 0;
    SLListNode* head = nullptr;
    void append(int value)
    {
        SLListNode* newHead = new SLListNode(value);
        if (head)
        {
            newHead->next = head;
        }
        head = newHead;
        count++;
    }
    void distinct() //убирает дубликаты (если я правильно понял, то дубликаты - это повторяющиеся в списке значения)
    {
        SLListNode* selected = head;
        while(selected)
        {
            SLListNode* node1 = selected;
            while (node1->next)
            {
                if (selected->value == node1->next->value)
                {
                    count--;
                    if (node1->next->next)
                    {
                        node1->next = node1->next->next;
                    }
                    else
                    {
                        node1->next = nullptr;
                        break;
                    }
                }
                else node1 = node1->next;
            }
            selected = selected->next;
        }
    }
    int elementFromTheEnd(int backIndex)//понятно, что мог дойти до последнего и с конца отсчитывать, но решил сделать так
    {
        int normalIndex = count - backIndex - 1;
        return element(normalIndex);
    }
    int element(int index)
    {
        auto node1 = head;
        for (int i = 0; i < index; i++)
        {
            node1 = node1->next;
        }
        return node1->value;
    }
};

int main()
{
    //1.1
    Matrix3x3 res = Matrix3x3();
    res.fillRandomElements(-10, 9);
    res.print();
    cout << endl;
    for (int i = 0; i < 3; i++)
        cout << " " << res.sumRow(i);
    cout << endl;
    for (int i = 0; i < 3; i++)
        cout << " " << res.minColumn(i) << " и " << res.maxColumn(i);
    cout << endl;
    cout << res.sumPrincipalDiag() << " " << res.sumSecondaryDiag();
    cout << endl << res.productPrincipalDiag() << " " << res.productSecondaryDiag() << endl;

    cout << endl;
    //1.2
    MatrixXnX res1(5);
    res1.fillRandomElements(0, 3);
    res1.print();
    cout << endl;
    for (int i = 0; i < res1.size; i++)
        cout << " " << res1.sumRow(i);
    cout << endl;
    for (int i = 0; i < res1.size; i++)
        cout << " " << res1.minColumn(i) << " и " << res1.maxColumn(i);
    cout << endl;
    cout << res1.sumPrincipalDiag() << " " << res1.sumSecondaryDiag();
    cout << endl << res1.productPrincipalDiag() << " " << res1.productSecondaryDiag() << endl << endl << endl;

    //2 и 3
    SingleLinkedList list;
    list.append(1);
    list.append(1);
    list.append(3);
    list.append(1);
    list.append(3);
    list.distinct();
    cout << list.count << endl; // выведет 2

    auto node = list.head;
    while (node)
    {
        cout << node->value << " ";
        node = node->next;
    } //выведет 3 1

    cout << endl << list.elementFromTheEnd(0) << " " << list.elementFromTheEnd(1); // выведет 1 3
}


