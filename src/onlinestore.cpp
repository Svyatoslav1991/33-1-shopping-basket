#include "onlinestore.h"
#include <stdexcept>
#include <iostream>

void OnlineStore::validateArticle(std::string article) const
{
    if (m_database.find(article) == m_database.end()) 
    {
        throw std::invalid_argument("The product with the specified article number was not found in the store database");
    }
}

//------------------------------------------------------------------------------------------

void OnlineStore::validateQuantity(int quantity) const
{
    if (quantity <= 0) 
    {
        throw std::invalid_argument("Product quantity must be a positive number");
    }
}

//------------------------------------------------------------------------------------------

void OnlineStore::validateInventory(std::string article, int quantity) const
{
    this->validateArticle(article);

    if (quantity > m_database.at(article)) 
    {
        throw std::invalid_argument("Insufficient quantity of goods in stock");
    }
}

//------------------------------------------------------------------------------------------

void OnlineStore::addItemToStore(std::string article, int quantity)
{
    this->validateQuantity(quantity);

    m_database[article] += quantity;
}

//------------------------------------------------------------------------------------------

void OnlineStore::add(std::string article, int quantity)
{
    this->validateQuantity(quantity);
    this->validateInventory(article, quantity);

    m_basket[article] += quantity;
    m_database[article] -= quantity;
}

//------------------------------------------------------------------------------------------

void OnlineStore::remove(std::string article, int quantity)
{
    validateQuantity(quantity);

    auto it = m_basket.find(article);
    if (it == m_basket.end()) 
    {
        throw std::invalid_argument("Product with the specified article was not found in the cart");
    }

    if (quantity > it->second) 
    {
        throw std::invalid_argument("There are not enough items in the cart to delete");
    }

    it->second -= quantity;
    m_database[article] += quantity;

    if (it->second == 0) 
    {
        m_basket.erase(it);
    }
}

//------------------------------------------------------------------------------------------

void OnlineStore::printBasket() const
{
    std::cout << "\tBasket:\n";
    for (const auto& item : m_basket) 
    {
        std::cout << "Article: " << item.first << "\t Quantity: " << item.second << "\n";
    }
    std::cout << "\n";
}

//------------------------------------------------------------------------------------------

void OnlineStore::printDataBase() const
{
    std::cout << "\tData Base:\n";
    for (const auto& item : m_database)
    {
        std::cout << "Article: " << item.first << "\t Quantity: " << item.second << "\n";
    }
    std::cout << "\n";
}

//------------------------------------------------------------------------------------------
