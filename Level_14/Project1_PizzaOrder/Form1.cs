using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Project1_PizzaOrder
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        void UpdateSize()
        {
            UpdateTotalPrice();

            if (rbSmall.Checked)
            {
                varLabelSize.Text = "Small";
                return;
            }

            if (rbMedium.Checked)
            {
                varLabelSize.Text = "Medium";
                return;
            }

            if (rbLarge.Checked)
            {
                varLabelSize.Text = "Large";
                return;
            }
        }

        void UpdateToppings()
        {

            UpdateTotalPrice();

            string sToppings = "";

            if (chkExtraCheese.Checked)
            {
                sToppings = "Extra Cheese";
            }


            if (chkOnion.Checked)
            {
                sToppings += ", Onion";
            }

            if (chkMushrooms.Checked)
            {
                sToppings += ", Mushrooms";
            }

            if (chkOlives.Checked)
            {
                sToppings += ", Olives";
            }

            if (chkTomatos.Checked)
            {
                sToppings += ", Tomatos";
            }

            if (chkGreenPeppers.Checked)
            {
                sToppings += ", Green Peppars";
            }

            if (sToppings.StartsWith(","))
            {
                sToppings = sToppings.Substring(1, sToppings.Length - 1).Trim();
            }

            if (sToppings == "")
            {
                sToppings = "No Toppings";
            }
            varToppingsList.Text = sToppings;
        }

        void UpdateCrust()
        {
            UpdateTotalPrice();
            if (rbThinCrust.Checked)
            {
                varLabelCrustType.Text = "Think Crust";
                return;
            }

            if (rbThickCrust.Checked)
            {
                varLabelCrustType.Text = "Thick Crust";
                return;
            }

        }

        void UpdateWhereToEat()
        {
            UpdateTotalPrice();

            if (rbEatIn.Checked)
            {
                varLabelWhereToEat.Text = "Eat In.";
                return;
            }

            if (rbTakeOut.Checked)
            {
                varLabelWhereToEat.Text = "Take Out.";
                return;
            }

        }

        byte GetSelectedSizePrice()
        {
            if (rbSmall.Checked)
            {
                return Convert.ToByte(rbSmall.Tag);
            }
            else if (rbMedium.Checked)
            {
                return Convert.ToByte(rbMedium.Tag);
            }
            else
            {
                return Convert.ToByte(rbLarge.Tag);
            }
        }

        byte CalculateToppingsPrice()
        {
            byte ToppingsTotalPrice = 0;

            if (chkExtraCheese.Checked)
            {
                ToppingsTotalPrice += Convert.ToByte(chkExtraCheese.Tag);
            }

            if (chkOnion.Checked)
            {
                ToppingsTotalPrice += Convert.ToByte(chkOnion.Tag);
            }

            if (chkMushrooms.Checked)
            {
                ToppingsTotalPrice += Convert.ToByte(chkMushrooms.Tag);
            }

            if (chkOlives.Checked)
            {
                ToppingsTotalPrice += Convert.ToByte(chkOlives.Tag);
            }

            if (chkTomatos.Checked)
            {
                ToppingsTotalPrice += Convert.ToByte(chkTomatos.Tag);
            }

            if (chkGreenPeppers.Checked)
            {
                ToppingsTotalPrice += Convert.ToByte(chkTomatos.Tag);
            }

            return ToppingsTotalPrice;
        }

        byte GetSelectedCrutPrice()
        {
            if (rbThinCrust.Checked)
            {
                return Convert.ToByte(rbThinCrust.Tag);
            }

            else
            {
                return Convert.ToByte(rbThickCrust.Tag);
            }
        }

        byte CalculateTotalPrice()
        {
            return Convert.ToByte(GetSelectedSizePrice() +
                    CalculateToppingsPrice() + GetSelectedCrutPrice());
        }

        void UpdateTotalPrice()
        {
            varLabelTotalPrice.Text = "$" + CalculateTotalPrice().ToString();
        }

        void UpdateOrderSummary()
        {
            UpdateSize();
            UpdateToppings();
            UpdateCrust();
            UpdateWhereToEat();
            UpdateTotalPrice();
        }

        void ResetForm()
        {
            //reset Groups
            gbLeftSide.Enabled = true;
            gbCenter.Enabled = true;
        
            //reset Size
            rbMedium.Checked = true;

            //reset Toppings.
            chkExtraCheese.Checked = false;
            chkOnion.Checked = false;
            chkMushrooms.Checked = false;
            chkOlives.Checked = false;
            chkTomatos.Checked = false;
            chkGreenPeppers.Checked = false;

            //reset CrustType
            rbThinCrust.Checked = true;

            //reset Where to Eat
            rbEatIn.Checked = true;

            //Reset Order Button
            btnOrderPizza.Enabled = true;
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            UpdateOrderSummary();
        }

        private void rbSize_Click(object sender, EventArgs e)
        {
            UpdateSize();
        }

        private void chkToppings_Click(object sender, EventArgs e)
        {
            UpdateToppings();
        }

        private void rbCrust_Click(object sender, EventArgs e)
        {
            UpdateCrust();
        }

        private void rbWhereToEat_Click(object sender, EventArgs e)
        {
            UpdateWhereToEat();
        }

        private void btnOrderPizza_Click(object sender, EventArgs e)
        {

            if (MessageBox.Show("Confirm Order", "Confirm",
                MessageBoxButtons.OKCancel, MessageBoxIcon.Question) == DialogResult.OK)
            {
                MessageBox.Show("Order Placed Successfully", "Success",
                    MessageBoxButtons.OK, MessageBoxIcon.Information);

                btnOrderPizza.Enabled = false;
                gbLeftSide.Enabled = false;
                gbCenter.Enabled = false;

            }
            else

                MessageBox.Show("Update your order", "Update",
                    MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
        }
        
        private void btnResetForm_Click(object sender, EventArgs e)
        {
            ResetForm();
            UpdateOrderSummary();
        }

    }
}
