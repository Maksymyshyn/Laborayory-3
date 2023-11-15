using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WinFormsApp6
{
    internal class Classforapp6
    {
        public static class MathHelper
        {
            public static bool IsMaxMultipleOfZ(int x, int y)
            {
                int z = Math.Max(x.ToString().Length, y.ToString().Length);
                int maxValue = Math.Max(x, y);
                return maxValue % z == 0;
            }

            public static bool IsSumOfDigitsDivisible(int x, int y)
            {
                int smallerNumber = Math.Min(x, y);
                int largerNumber = Math.Max(x, y);

                int smallerSumOfDigits = GetSumOfDigits(smallerNumber);
                int largerDigitCount = largerNumber.ToString().Length;

                return smallerSumOfDigits % largerDigitCount == 0;
            }

            private static int GetSumOfDigits(int number)
            {
                int sum = 0;
                while (number != 0)
                {
                    sum += number % 10;
                    number /= 10;
                }
                return sum;
            }
        }

    }
}
