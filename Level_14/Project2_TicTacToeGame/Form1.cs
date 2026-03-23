using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Project2_TicTacToeGame
{
    public partial class Form1 : Form
    {

        private enum enPlayers
        {
            NoPlayer,
            Player1,
            Player2
        }

        private enPlayers NextPlayer = enPlayers.NoPlayer;

        private void NextPlayerTurn() 
        {
            if (NextPlayer == enPlayers.NoPlayer || NextPlayer == enPlayers.Player2)
            {
                NextPlayer = enPlayers.Player1;
                return ;
            }
            else
            {
                NextPlayer = enPlayers.Player1;
            }
        }

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            Pen Pen = new Pen(
                        color: Color.White,
                        width: 10);

            Pen.StartCap = System.Drawing.Drawing2D.LineCap.Round;
            Pen.EndCap = System.Drawing.Drawing2D.LineCap.Round;

            // start x = 360 , y = 250 ; size = 450
            e.Graphics.DrawLine(Pen, 360, 250, 800, 250);
            e.Graphics.DrawLine(Pen, 360, 400, 800, 400);
            e.Graphics.DrawLine(Pen, 510, 110, 510, 540);
            e.Graphics.DrawLine(Pen, 660, 110, 660, 540);
        }

        private void ShowMesageBox()
        {
            MessageBox.Show(
               caption: "Wrong Move",
               text: "You Can't Choose This",
               icon: MessageBoxIcon.Error,
               buttons: MessageBoxButtons.OK
               );
        }

        private void Box1_Click(object sender, EventArgs e)
        {
            if(Box1.Tag.ToString() != "Default")
            {
                ShowMesageBox();
            }
            else
            {
                Box1.Image = Properties.Resources.X;
                Box1.Tag = "X" ;
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            Form1_Paint(sender, e);
        }

        private void Form1_Paint(object sender, EventArgs e)
        {
            throw new NotImplementedException();
        }

    }
}
