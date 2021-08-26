#include "Account.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::setw;
using std::setfill;

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit )
	:  _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	_displayTimestamp();
	cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << endl;
	_nbAccounts++;
	_totalAmount += _amount;
}

Account::~Account()
{
	_displayTimestamp();
	cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << endl;
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
	cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount;
	cout << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals;
	cout << endl;
	return ;
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	cout << "index:" << _accountIndex << ";p_amount:" << _amount;
	cout << ";deposit:";
	if (deposit <= 0)
	{
		cout << "refused" << endl;
		return ;
	}
	_amount += deposit;
	++_nbDeposits;
	_totalAmount += deposit;
	++_totalNbDeposits;
	cout << deposit << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits;
	cout << endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	cout << "index:" << _accountIndex << ";p_amount:" << _amount;
	cout << ";withdrawal:";
	if (withdrawal <= 0 || _amount < withdrawal)
	{
		cout << "refused" << endl;
		return false;
	}
	_amount -= withdrawal;
	++_nbWithdrawals;
	_totalAmount -= withdrawal;
	++_totalNbWithdrawals;
	cout << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals;
	cout << endl;
	return true;
}

int		Account::checkAmount(void) const
{
	return (_amount);
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	cout << "index:" << _accountIndex << ";amount:" << _amount;
	cout << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals;
	cout << endl;
}

void	Account::_displayTimestamp(void)
{
	time_t		now = time(0);
	struct tm	*parsed_time = localtime(&now);
	cout << '[';
	cout << setfill('0') << setw(4) << parsed_time->tm_year + 1900;
	cout << setw(2) << parsed_time->tm_mon + 1;
	cout << setw(2) << parsed_time->tm_mday << '_';
	cout << setw(2) << parsed_time->tm_hour;
	cout << setw(2) << parsed_time->tm_min;
	cout << setw(2) << parsed_time->tm_sec << "] ";
}
