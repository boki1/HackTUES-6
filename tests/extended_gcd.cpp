int EuclideanGCD(int num1, int num2)
{
    if (num1 == 0)
    {
        return num2;
    }

    return EuclideanGCD(num2 % num1, num1);
}

int main() {

	int gcd = EuclideanGCD(42, 3);

	std::cout << gcd << std::endl;
	return 0;
}

