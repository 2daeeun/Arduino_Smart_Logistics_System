using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        private ListBox listBox2;

        public Form1()
        {
            InitializeComponent();

            // listBox1 항목 추가
            listBox1.Items.Add("원피스 피규어");
            listBox1.Items.Add("수박");

            // listBox1 이벤트 핸들러 추가
            listBox1.SelectedIndexChanged += new EventHandler(listBox1_SelectedIndexChanged);

            // 폼 클릭 이벤트 핸들러 추가
            this.MouseClick += new MouseEventHandler(Form1_MouseClick);
        }

        private void button1_Click(object sender, EventArgs e)
        {

        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void listView1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void listBox2_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (listBox1.SelectedItem != null)
            {
                string selectedItem = listBox1.SelectedItem.ToString();

                // 이미 생성된 listBox2가 있다면 제거
                if (listBox2 != null)
                {
                    this.Controls.Remove(listBox2);
                    listBox2.Dispose();
                }

                // 새로운 listBox2 생성
                listBox2 = new ListBox();

                if (selectedItem == "원피스 피규어")
                {
                    listBox2.Items.Add("상품 이름 : 원피스 피규어");
                    listBox2.Items.Add("상품 구분 : 잡화");
                    listBox2.Items.Add("발송자 : 홍길동");
                    listBox2.Items.Add("수령자 : 이순신");
                    listBox2.Items.Add("발송 지역 : 서울");
                }
                else if (selectedItem == "수박")
                {
                    listBox2.Items.Add("상품 이름 : 수박");
                    listBox2.Items.Add("상품 구분 : 식품");
                    listBox2.Items.Add("발송자 : 안중근");
                    listBox2.Items.Add("수령자 : 유관순");
                    listBox2.Items.Add("발송 지역 : 제주");
                }

                // listBox2 폰트 설정
                listBox2.Font = new Font(listBox2.Font.FontFamily, 16);

                // listBox2 위치와 크기 설정
                listBox2.Location = new Point(listBox1.Right + 20, listBox1.Top);
                listBox2.Size = new Size(300, 200);

                // listBox2 클릭 이벤트 핸들러 추가
                listBox2.MouseClick += new MouseEventHandler(listBox2_MouseClick);

                // 폼에 새로운 listBox2 추가
                this.Controls.Add(listBox2);
            }
        }

        private void listBox2_MouseClick(object sender, MouseEventArgs e)
        {
            // listBox2의 클릭 이벤트를 처리하여 클릭된 영역을 확인합니다.
        }

        private void Form1_MouseClick(object sender, MouseEventArgs e)
        {
            // listBox2가 생성되어 있고, 클릭된 위치가 listBox2의 외부라면 listBox2를 제거합니다.
            if (listBox2 != null && !listBox2.Bounds.Contains(e.Location))
            {
                this.Controls.Remove(listBox2);
                listBox2.Dispose();
                listBox2 = null;
            }
        }

        private void label4_Click(object sender, EventArgs e)
        {

        }
    }
}
