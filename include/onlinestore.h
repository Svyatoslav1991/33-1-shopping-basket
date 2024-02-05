#include <unordered_map>
#include <string>

class OnlineStore {
private:
	std::unordered_map<std::string, int> m_database;
	std::unordered_map<std::string, int> m_basket;

	void validateArticle(std::string article) const;
	void validateQuantity(int quantity) const;
	void validateInventory(std::string article, int quantity) const;

public:
	void addItemToStore(std::string article, int quantity);
	void add(std::string article, int quantity);
	void remove(std::string article, int quantity);
	void printBasket() const;
	void printDataBase() const;
};