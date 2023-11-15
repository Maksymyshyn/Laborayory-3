using static WinFormsApp6.Classforapp6;

namespace WinFormsApp6
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (int.TryParse(textBoxX.Text, out int x) && int.TryParse(textBoxY.Text, out int y))
            {
                bool isMaxMultipleOfZ = MathHelper.IsMaxMultipleOfZ(x, y);
                bool isSumOfDigitsDivisible = MathHelper.IsSumOfDigitsDivisible(x, y);

                MessageBox.Show(isMaxMultipleOfZ ? "Так" : "Ні", "Чи max{ х, у} кратне z, де z – кількість цифр числа у?");
                MessageBox.Show(isSumOfDigitsDivisible ? "Так" : "Ні", "Чи сума цифр меншого з двох заданих чисел ділиться без остачі на кількість цифр більшого з двох заданих чисел х, у?");
            }
            else
            {
                MessageBox.Show("Будь ласка, введіть дійсні цілі значення для x і y.", "Eror");
            }
        }

    }
}
