#include <Account.hpp>
#include <iostream>

int 	Account::_nbAccounts=0;
int 	Account::_totalAmount=0;
int 	Account::_totalNbDeposits=0;
int 	Account::_totalNbWithdrawals=0;

int 	Account::getTotalAmount(void) {
	return Account::_totalAmount;
}

int 	Account::getNbAccounts(void) {
	return Account::_nbAccounts;
}

int 	Account::getNbDeposits() {
	return _totalNbDeposits;
}

int 	Account::getNbWithdrawals() {
	return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos(void) {
	Account::_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts
	<< ";total:" << getTotalAmount()
	<< ";deposits:" << getNbDeposits()
	<< ";withdrawals:" << getNbWithdrawals() << std::endl;
}

Account::Account(int initialDeposit): _accountIndex(_nbAccounts)
	, _amount(initialDeposit), _nbDeposits(0), _nbWithdrawals(0) {
	_nbAccounts++;
	_totalAmount += initialDeposit;
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:"
	<< _amount << ";created" << std::endl;
}

Account::~Account(void) {
//	--_nbAccounts;
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:"
	<< _amount << ";closed" << std::endl;
	return;
}

void	Account::makeDeposit(int deposit) {
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex
	<< ";p_amount:" << _amount << ";deposit:" << deposit
	<< ";amount:" << _amount + deposit << ";nb_deposits:"
	<< _nbDeposits + 1 << std::endl;
	_amount += deposit;
	_nbDeposits += 1;
	_totalAmount += deposit;
	_totalNbDeposits += 1;
}

bool 	Account::makeWithdrawal(int withdrawal) {
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex
	<< ";p_amount:" << _amount << ";withdrawal:";
	if (withdrawal <= _amount) {
		std::cout << withdrawal << ";amount:"
		<< (_amount - withdrawal) << ";nb_withdrawals:"
		<< _nbWithdrawals + 1 << std::endl;
		_amount -= withdrawal;
		_nbWithdrawals +=1;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals +=1;
		return true;
	} else {
		std::cout << "refused" << std::endl;
		return false; // remove
	}
}

int 	Account::checkAmount(void) const {
	return _amount; // remove
}

void 	Account::displayStatus() const {
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex
	<< ";amount:" << _amount << ";deposits:"
	<< _nbDeposits << ";withdrawals:" << _nbWithdrawals
	<< std::endl;
}

void 	Account::_displayTimestamp(void) {
	time_t rawtime;
	struct tm * timeinfo;
	char buffer [80];
	time (&rawtime);
	timeinfo = localtime (&rawtime);

	std::strftime(buffer, 80, "%Y%m%d_%H%M%S", timeinfo);
	std::cout << "[" << buffer << "] ";
}