#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
using namespace std;

class FileProcessResult abstract
{
public:
    virtual void get_message() = 0;
};

template<typename T>
class FileInterface abstract
{
public:
    virtual FileProcessResult* open(ios_base::openmode mode) = 0;
    virtual FileProcessResult* close() = 0;
    virtual FileProcessResult* write(T data, ios_base::openmode mode) = 0;
    virtual FileProcessResult* read(T& data, ios_base::openmode mode) = 0;
};

class FileOpenSuccess : public FileProcessResult
{
public:
    FileOpenSuccess() = default;
    void get_message() override
    {
        cout << "File opened successfully" << endl;
    }
};

class FileOpenError : public FileProcessResult
{
public:
    FileOpenError() = default;
    void get_message() override
    {
        cout << "Error opening file" << endl;
    }
};

class FileCloseSuccess : public FileProcessResult
{
public:
    FileCloseSuccess() = default;
    void get_message() override
    {
        cout << "File closed successfully" << endl;
    }
};

class FileWriteSuccess : public FileProcessResult
{
public:
    FileWriteSuccess() = default;
    void get_message() override
    {
        cout << "Data written successfully" << endl;
    }
};

class FileWriteError : public FileProcessResult
{
    exception e;
public:
    FileWriteError() = default;
    FileWriteError(exception e)
    {
        this->e = e;
    }
    void get_message() override
    {
        cout << "Error writing data" << endl;
    }
};

class FileReadSuccess : public FileProcessResult
{
public:
    FileReadSuccess() = default;
    void get_message() override
    {
        cout << "Data read successfully" << endl;
    }
};

class FileReadError : public FileProcessResult
{
    exception e;
public:
    FileReadError() = default;
    FileReadError(exception e)
    {
        this->e = e;
    }
    void get_message() override
    {
        cout << "Error writing data" << endl;
    }
};

template<typename T>
class FileService : public FileInterface<T>
{
    string filename;
    fstream file;
public:
    FileService(string filename)
    {
        this->filename = filename;
    }
    FileProcessResult* open(ios_base::openmode mode) override
    {
        FileProcessResult* result = nullptr;
        file.open(filename, mode);
        if (file.is_open())
        {
            result = new FileOpenSuccess();
        }
        else
        {
            result = new FileOpenError();
        }
        return result;
    }
    FileProcessResult* close() override
    {
        file.close();
        return new FileCloseSuccess();
    }
    FileProcessResult* write(T data, ios_base::openmode mode) override
    {
        try
        {
            FileProcessResult* result = this->open(mode);
            result->get_message();
            if (typeid(*result) == typeid(FileOpenSuccess))
            {
                if (mode == ios::app || mode == ios::out || mode == (ios::out | ios::binary) || mode == (ios::app | ios::binary))
                {
                    file.write((char*)&data, sizeof(T));
                }
                else
                {
                    return new FileWriteError();
                }
                result = this->close();
                result->get_message();
                return new FileWriteSuccess();
            }
            else if (typeid(*result) == typeid(FileOpenError))
            {
                return new FileWriteError();
            }
        }
        catch (exception e)
        {
            return new FileWriteError(e);
        }
    }

    FileProcessResult* read(T& data, ios_base::openmode mode) override
    {
        try
        {
            FileProcessResult* result = this->open(mode);
            result->get_message();
            if (typeid(*result) == typeid(FileOpenSuccess))
            {
                if (mode == ios::in || mode == (ios::in | ios::binary))
                {
                    file.read((char*)&data, sizeof(T));
                }
                else
                {
                    return new FileWriteError();
                }
                result = this->close();
                result->get_message();
                return new FileReadSuccess();
            }
            else if (typeid(*result) == typeid(FileOpenError))
            {
                return new FileReadError();
            }
        }
        catch (exception e)
        {
            return new FileReadError(e);
        }
    }
};


class User
{
public:
    char name[20];
    User()
    {
        strcpy(this->name, "");
    }
    User(const char* name)
    {
        strcpy(this->name, name);
    }
    void print()
    {
        cout << "Name: " << name << endl;
    }
};

int main() {
    try
    {
        User user("John");
        FileService<User> file("data.bin");
        FileProcessResult* result = nullptr;
        result = file.write(user, ios::out | ios::binary);
        result->get_message();
        User new_user;
        result = file.read(new_user, ios::in | ios::binary);
        new_user.print();
        result->get_message();
    }
    catch (FileProcessResult* file_error)
    {
        file_error->get_message();
    }
    return 0;
}
//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <fstream>
//using namespace std;
//
//class FileProcessResult abstract
//{
//public:
//    virtual void get_message() = 0;
//};
//
//template<typename T>
//class FileInterface abstract
//{
//public:
//    virtual FileProcessResult* open(ios_base::openmode mode) = 0;
//    virtual FileProcessResult* close() = 0;
//    virtual FileProcessResult* write(T data, ios_base::openmode mode) = 0;
//    virtual FileProcessResult* read(T& data, ios_base::openmode mode) = 0;
//};
//
//class FileOpenSuccess : public FileProcessResult
//{
//public:
//    FileOpenSuccess() = default;
//    void get_message() override
//    {
//        cout << "File opened successfully" << endl;
//    }
//};
//
//class FileOpenError : public FileProcessResult
//{
//public:
//    FileOpenError() = default;
//    void get_message() override
//    {
//        cout << "Error opening file" << endl;
//    }
//};
//
//class FileCloseSuccess : public FileProcessResult
//{
//public:
//    FileCloseSuccess() = default;
//    void get_message() override
//    {
//        cout << "File closed successfully" << endl;
//    }
//};
//
//class FileWriteSuccess : public FileProcessResult
//{
//public:
//    FileWriteSuccess() = default;
//    void get_message() override
//    {
//        cout << "Data written successfully" << endl;
//    }
//};
//
//class FileWriteError : public FileProcessResult
//{
//    exception e;
//public:
//    FileWriteError() = default;
//    FileWriteError(exception e)
//    {
//        this->e = e;
//    }
//    void get_message() override
//    {
//        cout << "Error writing data" << endl;
//    }
//};
//
//class FileReadSuccess : public FileProcessResult
//{
//public:
//    FileReadSuccess() = default;
//    void get_message() override
//    {
//        cout << "Data read successfully" << endl;
//    }
//};
//
//class FileReadError : public FileProcessResult
//{
//    exception e;
//public:
//    FileReadError() = default;
//    FileReadError(exception e)
//    {
//        this->e = e;
//    }
//    void get_message() override
//    {
//        cout << "Error writing data" << endl;
//    }
//};
//
//template<typename T>
//class FileService : public FileInterface<T>
//{
//    string filename;
//    fstream file;
//public:
//    FileService(string filename)
//    {
//        this->filename = filename;
//    }
//    FileProcessResult* open(ios_base::openmode mode) override
//    {
//        FileProcessResult* result = nullptr;
//        file.open(filename, mode);
//        if (file.is_open())
//        {
//            result = new FileOpenSuccess();
//        }
//        else
//        {
//            result = new FileOpenError();
//        }
//        return result;
//    }
//    FileProcessResult* close() override
//    {
//        file.close();
//        return new FileCloseSuccess();
//    }
//    FileProcessResult* write(T data, ios_base::openmode mode) override
//    {
//        try
//        {
//            FileProcessResult* result = this->open(mode);
//            result->get_message();
//            if (typeid(*result) == typeid(FileOpenSuccess))
//            {
//                if (mode == ios::app || mode == ios::out || mode == (ios::out | ios::binary) || mode == (ios::app | ios::binary))
//                {
//                    file.write((char*)&data, sizeof(T));
//                }
//                else
//                {
//                    return new FileWriteError();
//                }
//                result = this->close();
//                result->get_message();
//                return new FileWriteSuccess();
//            }
//            else if (typeid(*result) == typeid(FileOpenError))
//            {
//                return new FileWriteError();
//            }
//        }
//        catch (exception e)
//        {
//            return new FileWriteError(e);
//        }
//    }
//
//    FileProcessResult* read(T& data, ios_base::openmode mode) override
//    {
//        try
//        {
//            FileProcessResult* result = this->open(mode);
//            result->get_message();
//            if (typeid(*result) == typeid(FileOpenSuccess))
//            {
//                if (mode == ios::in || mode == (ios::in | ios::binary))
//                {
//                    file.read((char*)&data, sizeof(T));
//                }
//                else
//                {
//                    return new FileWriteError();
//                }
//                result = this->close();
//                result->get_message();
//                return new FileReadSuccess();
//            }
//            else if (typeid(*result) == typeid(FileOpenError))
//            {
//                return new FileReadError();
//            }
//        }
//        catch (exception e)
//        {
//            return new FileReadError(e);
//        }
//    }
//};
//
//
//class User
//{
//public:
//    string name;
//    User()
//    {
//        name = "";
//    }
//    User(const char* name)
//    {
//        this->name = name;
//    }
//    void print()
//    {
//        cout << "Name: " << name << endl;
//    }
//};
//
//int main() {
//    try
//    {
//        User user("John");
//        FileService<User> file("data.bin");
//        FileProcessResult* result = nullptr;
//        result = file.write(user, ios::out | ios::binary);
//        result->get_message();
//        User new_user;
//        result = file.read(new_user, ios::in | ios::binary);
//        new_user.print();
//        result->get_message();
//        delete result;
//    }
//    catch (FileProcessResult* file_error)
//    {
//        file_error->get_message();
//    }
//    return 0;
//}