
int gcd(int x, int y) {
	if (x == 0) return y;
	if (y == 0) return x;
	return gcd(y, x % y);
}
bool isprime(int n) {
	if (n <= 1) return false;
	if (n <= 3) return true;

	if (n % 2 == 0 || n % 3 == 0) return false;

	for (int i = 5; i * i <= n; i += 6)
		if (n % i == 0 || n % (i + 2) == 0)
			return false;

	return true;
}

bool prime[15000105];
void sieve(int n) {
	for (int i = 0; i <= n; i++) prime[i] = 1;
	for (int p = 2; p * p <= n; p++) {
		if (prime[p] == true) {
			for (int i = p * p; i <= n; i += p)
				prime[i] = false;
		}
	}
	prime[1] = prime[0] = 0;
}

vector<int> primelist;
bool __primes_generated__ = 0;

void genprimes(int n) {
	__primes_generated__ = 1;
	sieve(n + 1);
	for (int i = 2; i <= n; i++) if (prime[i]) primelist.push_back(i);
}

vector<int> factors(int n) {
	if (!__primes_generated__) {
		cerr << "CALL gen_primes" << endl;
		exit(1);
	}
	vector<int> facs;

	for (int i = 0; primelist[i] * primelist[i] <= n && i <primelist.size(); i++) {
		if (n % primelist[i] == 0) {
			while (n % primelist[i] == 0) {
				n /= primelist[i];
				facs.push_back(primelist[i]);
			}
		}
	}
	if (n > 1) {
		facs.push_back(n);
	}
	sort(facs.begin(), facs.end());
	unique(all(facs));
	return facs;
}

vector<int> getdivs(ll n) {
	vector<int> divs;
	for (int i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			divs.push_back(i);
			divs.push_back(n / i);
		}
	}
	unique(all(divs));
	return divs;
}
