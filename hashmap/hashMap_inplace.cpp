#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

template <typename K, typename V>
class Tupla
{
private:
    K key;
    V value;
    Tupla *prox;

public:
    Tupla(K c, V v)
    {
        key = c;
        value = v;
        prox = NULL;
    }

    K getKey()
    {
        return key;
    }

    V getValue()
    {
        return value;
    }

    Tupla *getNext()
    {
        return prox;
    }

    void setValue(V value)
    {
        value = value;
    }

    void setNext(Tupla *prox)
    {
        Tupla::prox = prox;
    }
};

template <typename Key, typename Value>
class TableHash
{
private:
    Tupla<K, V> **table;
    int buckets_count;
    int size;

    int hashKey(K key)
    {
        auto hash_id = (int)hash<K>{}(key);
        return abs(hash_id % this->buckets_count);
    }

    void increase_array()
    {
        int old_buckets = this->buckets_count;
        buckets_count = buckets_count * 8;
        table = (Tupla<K, V> **)realloc(table, sizeof(Tupla<K, V> *) * buckets_count);
        for (int i = old_buckets; i < buckets_count; i++)
        {
            table[i] = NULL;
        }

        for (int i = 0; i < old_buckets; i++)
        {
            if (table[i] != NULL)
            {
                auto head = table[i];
                Tupla<K, V> *aux = NULL;
                while (head != NULL)
                {
                    aux = head;
                    size--;
                    head = head->getProx();
                    inserir(aux->getKey(), aux->getvalue());
                    aux = NULL;
                }
            }
        }
    }

public:
    int size()
    {
        return this->size;
    }

    int bucket_count()
    {
        return this->buckets_count;
    }

    double load_factor()
    {
        return (double)size / (double)buckets_count;
    }

    tableHash()
    {
        buckets_count = 8;
        size = 0;
        table = (Tupla<K, V> **)calloc(sizeof(Tupla<K, V> *), buckets_count);

        for (int i = 0; i < buckets_count; i++)
        {
            table[i] = NULL;
        }
    }

    bool contemkey(K key)
    {
        int idx = hashKey(key);

        if (table[idx] != NULL)
        {
            Tupla<K, V> *top = table[idx];
            while (top->getKey() != key)
            {
                if (top->getProx() == NULL)
                {
                    return false;
                }
                top = top->getProx();
            }
            return true;
        }
        return false;
    }

    V getvalue(K key)
    {
        int idx = hashKey(key);
        if (table[idx] == NULL)
        {
            cout << "key " << key << " não está na table" << endl;
            return 0;
        }
        auto top = table[idx];
        while (top->getKey() != key)
        {
            if (top->getProx() == NULL)
            {
                cout << "key não está na table" << endl;
                return 0;
            }
            top = top->getProx();
        }
        return top->getvalue();
    }

    vector<K> getKeys()
    {
        vector<K> ans;

        for (int i = 0; i < buckets_count; i++)
        {
            if (table[i] != NULL)
            {
                auto top = table[i];
                while (top != NULL)
                {
                    ans.push_back(top->getKey());
                    top = top->getProx();
                }
            }
        }

        return ans;
    }

    void inserir(K key, V value)
    {
        int idx = hashKey(key);
        if (load_factor() >= 1.0)
        {
            increase_array();
        }
        this->size++;
        auto newTuple = new Tupla<K, V>(key, value);
        if (table[idx] == NULL)
        {
            cout << "ITEM INSERIDO\n";

            table[idx] = newTuple;

            return;
        }

        auto top = table[idx];
        while (top->getProx() != NULL)
        {
            if (top->getKey() == key)
            {
                top->setValue(value);
                cout << "ITEM EDITADO\n";
                return;
            }
            top = top->getProx();
        }
        if (top->getKey() == key)
        {
            cout << "ITEM EDITADO\n";
            top->setValue(value);
            return;
        }

        cout << "ITEM INSERIDO\n";
        top->setNext(newTuple);
    }

    void remover(K key)
    {
        int id = hashKey(key);

        if (table[id] != NULL)
        {
            Tupla<K, V> *top = table[id];
            Tupla<K, V> *aux = NULL;

            while (top->getKey() != key)
            {
                aux = top;
                top = top->getProx();
                if (top == NULL)
                {
                    cout << "key não existente." << endl;
                    return;
                }
            }

            if (aux == NULL)
            {
                table[id] = top->getProx();
            }
            else
            {
                aux->setNext(top->getProx());
            }
            size--;
            delete top;
        }
    }

    void clear()
    {
        for (int i = 0; i < buckets_count; i++)
        {
            auto head = table[i];
            while (head != NULL)
            {
                auto aux = head;
                head = head->getProx();
                delete aux;
            }
            table[i] = NULL;
        }
        delete[] table;

        this->buckets_count = 8;
        size = 0;

        table = (Tupla<K, V> **)calloc(sizeof(Tupla<K, V> *), buckets_count);
        return;
    }
};
