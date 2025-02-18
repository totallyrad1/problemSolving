int addDigits(int num) {
    int result;
    int digit;

    result = 0;
    digit = 0;
    while(num > 0)
    {
      digit = num % 10;
      num /= 10;
      result += digit;
    }
    if(result > 9)
      return addDigits(result);
    return result;
}