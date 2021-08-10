#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit )
	:  _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
	_nbAccounts++;
	_totalAmount += _amount;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount;
	std::cout << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals;
	std::cout << std::endl;
	return ;
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount;
	std::cout << ";deposit:";
	if (deposit <= 0)
	{
		std::cout << "refused" << std::endl;
		return ;
	}
	_amount += deposit;
	++_nbDeposits;
	_totalAmount += deposit;
	++_totalNbDeposits;
	std::cout << deposit << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits;
	std::cout << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount;
	std::cout << ";withdrawal:";
	if (withdrawal <= 0 || _amount < withdrawal)
	{
		std::cout << "refused" << std::endl;
		return false;
	}
	_amount -= withdrawal;
	++_nbWithdrawals;
	_totalAmount -= withdrawal;
	++_totalNbWithdrawals;
	std::cout << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals;
	std::cout << std::endl;
	return true;
}

int		Account::checkAmount(void) const
{
	return (_amount);
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount;
	std::cout << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals;
	std::cout << std::endl;
}

void	Account::_displayTimestamp(void)
{
	time_t		now = time(0);
	struct tm	*parsed_time = localtime(&now);
	std::cout << '[';
	std::cout << std::setfill('0') << std::setw(4) << parsed_time->tm_year + 1900;
	std::cout << std::setw(2) << parsed_time->tm_mon + 1;
	std::cout << std::setw(2) << parsed_time->tm_mday << '_';
	std::cout << std::setw(2) << parsed_time->tm_hour;
	std::cout << std::setw(2) << parsed_time->tm_min;
	std::cout << std::setw(2) << parsed_time->tm_sec << "] ";
}