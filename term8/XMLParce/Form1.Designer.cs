namespace XMLParce;

partial class Form1
{
    /// <summary>
    ///  Required designer variable.
    /// </summary>
    private System.ComponentModel.IContainer components = null;

    /// <summary>
    ///  Clean up any resources being used.
    /// </summary>
    /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
    protected override void Dispose(bool disposing)
    {
        if (disposing && (components != null))
        {
            components.Dispose();
        }
        base.Dispose(disposing);
    }

    #region Windows Form Designer generated code

    /// <summary>
    ///  Required method for Designer support - do not modify
    ///  the contents of this method with the code editor.
    /// </summary>
    private void InitializeComponent()
    {
        label1 = new Label();
        label2 = new Label();
        button1 = new Button();
        listBox1 = new ListBox();
        button2 = new Button();
        button3 = new Button();
        label3 = new Label();
        SuspendLayout();
        // 
        // label1
        // 
        label1.AutoSize = true;
        label1.Font = new Font("Segoe UI", 14F, FontStyle.Regular, GraphicsUnit.Point);
        label1.Location = new Point(12, 9);
        label1.Name = "label1";
        label1.Size = new Size(180, 25);
        label1.TabIndex = 0;
        label1.Text = "Файл содержимого";
        // 
        // label2
        // 
        label2.AutoSize = true;
        label2.Font = new Font("Segoe UI", 14F, FontStyle.Regular, GraphicsUnit.Point);
        label2.Location = new Point(12, 84);
        label2.Name = "label2";
        label2.Size = new Size(110, 25);
        label2.TabIndex = 1;
        label2.Text = "Файл стиля";
        // 
        // button1
        // 
        button1.BackColor = SystemColors.ControlDark;
        button1.Location = new Point(198, 10);
        button1.Name = "button1";
        button1.Size = new Size(145, 29);
        button1.TabIndex = 6;
        button1.Text = "Загрузить";
        button1.UseVisualStyleBackColor = false;
        button1.Click += button1_Click;
        // 
        // listBox1
        // 
        listBox1.FormattingEnabled = true;
        listBox1.ItemHeight = 15;
        listBox1.Location = new Point(458, 9);
        listBox1.Name = "listBox1";
        listBox1.Size = new Size(442, 499);
        listBox1.TabIndex = 7;
        // 
        // button2
        // 
        button2.BackColor = SystemColors.ControlDark;
        button2.Location = new Point(198, 85);
        button2.Name = "button2";
        button2.Size = new Size(145, 29);
        button2.TabIndex = 8;
        button2.Text = "Загрузить";
        button2.UseVisualStyleBackColor = false;
        button2.Click += button2_Click;
        // 
        // button3
        // 
        button3.BackColor = SystemColors.ControlDark;
        button3.Location = new Point(198, 167);
        button3.Name = "button3";
        button3.Size = new Size(145, 29);
        button3.TabIndex = 9;
        button3.Text = "Вперед";
        button3.UseVisualStyleBackColor = false;
        button3.Click += button3_Click;
        // 
        // label3
        // 
        label3.AutoSize = true;
        label3.Location = new Point(200, 213);
        label3.Name = "label3";
        label3.Size = new Size(0, 15);
        label3.TabIndex = 10;
        // 
        // Form1
        // 
        AutoScaleDimensions = new SizeF(7F, 15F);
        AutoScaleMode = AutoScaleMode.Font;
        BackColor = SystemColors.Control;
        ClientSize = new Size(912, 519);
        Controls.Add(label3);
        Controls.Add(button3);
        Controls.Add(button2);
        Controls.Add(listBox1);
        Controls.Add(button1);
        Controls.Add(label2);
        Controls.Add(label1);
        Name = "Form1";
        Text = "Form1";
        ResumeLayout(false);
        PerformLayout();
    }

    #endregion

    private Label label1;
    private Label label2;
    private Button button1;
    private ListBox listBox1;
    private Button button2;
    private Button button3;
    private Label label3;
}
