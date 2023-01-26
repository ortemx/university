<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class frmFun
    Inherits System.Windows.Forms.Form

    'Форма переопределяет dispose для очистки списка компонентов.
    <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Является обязательной для конструктора форм Windows Forms
    Private components As System.ComponentModel.IContainer

    'Примечание: следующая процедура является обязательной для конструктора форм Windows Forms
    'Для ее изменения используйте конструктор форм Windows Form.  
    'Не изменяйте ее в редакторе исходного кода.
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Me.lblx = New System.Windows.Forms.Label()
        Me.lbly = New System.Windows.Forms.Label()
        Me.txtX = New System.Windows.Forms.TextBox()
        Me.txtY = New System.Windows.Forms.TextBox()
        Me.lblB = New System.Windows.Forms.Label()
        Me.btnCalculate = New System.Windows.Forms.Button()
        Me.btnClear = New System.Windows.Forms.Button()
        Me.btnExit = New System.Windows.Forms.Button()
        Me.ListView1 = New System.Windows.Forms.ListView()
        Me.RadioButton1 = New System.Windows.Forms.RadioButton()
        Me.RadioButton2 = New System.Windows.Forms.RadioButton()
        Me.RadioButton3 = New System.Windows.Forms.RadioButton()
        Me.RadioButton4 = New System.Windows.Forms.RadioButton()
        Me.TextBox1 = New System.Windows.Forms.TextBox()
        Me.TextBox2 = New System.Windows.Forms.TextBox()
        Me.SuspendLayout()
        '
        'lblx
        '
        Me.lblx.AutoSize = True
        Me.lblx.Location = New System.Drawing.Point(60, 9)
        Me.lblx.Name = "lblx"
        Me.lblx.Size = New System.Drawing.Size(93, 13)
        Me.lblx.TabIndex = 0
        Me.lblx.Text = "ПЕРВОЕ ЧИСЛО"
        Me.lblx.TextAlign = System.Drawing.ContentAlignment.TopRight
        '
        'lbly
        '
        Me.lbly.AutoSize = True
        Me.lbly.Location = New System.Drawing.Point(413, 9)
        Me.lbly.Name = "lbly"
        Me.lbly.Size = New System.Drawing.Size(93, 13)
        Me.lbly.TabIndex = 1
        Me.lbly.Text = "ВТОРОЕ ЧИСЛО"
        Me.lbly.TextAlign = System.Drawing.ContentAlignment.TopRight
        '
        'txtX
        '
        Me.txtX.Location = New System.Drawing.Point(52, 37)
        Me.txtX.Name = "txtX"
        Me.txtX.Size = New System.Drawing.Size(126, 20)
        Me.txtX.TabIndex = 0
        '
        'txtY
        '
        Me.txtY.Location = New System.Drawing.Point(416, 37)
        Me.txtY.Name = "txtY"
        Me.txtY.Size = New System.Drawing.Size(124, 20)
        Me.txtY.TabIndex = 1
        '
        'lblB
        '
        Me.lblB.AutoSize = True
        Me.lblB.Location = New System.Drawing.Point(266, 344)
        Me.lblB.Name = "lblB"
        Me.lblB.Size = New System.Drawing.Size(58, 13)
        Me.lblB.TabIndex = 4
        Me.lblB.Text = "результат"
        Me.lblB.TextAlign = System.Drawing.ContentAlignment.TopRight
        '
        'btnCalculate
        '
        Me.btnCalculate.Location = New System.Drawing.Point(38, 404)
        Me.btnCalculate.Name = "btnCalculate"
        Me.btnCalculate.Size = New System.Drawing.Size(220, 51)
        Me.btnCalculate.TabIndex = 6
        Me.btnCalculate.Text = "Вычислить"
        Me.btnCalculate.UseVisualStyleBackColor = True
        '
        'btnClear
        '
        Me.btnClear.DialogResult = System.Windows.Forms.DialogResult.Cancel
        Me.btnClear.Location = New System.Drawing.Point(302, 405)
        Me.btnClear.Name = "btnClear"
        Me.btnClear.Size = New System.Drawing.Size(220, 48)
        Me.btnClear.TabIndex = 7
        Me.btnClear.Text = "Сброс"
        Me.btnClear.UseVisualStyleBackColor = True
        '
        'btnExit
        '
        Me.btnExit.DialogResult = System.Windows.Forms.DialogResult.Cancel
        Me.btnExit.Location = New System.Drawing.Point(563, 403)
        Me.btnExit.Name = "btnExit"
        Me.btnExit.Size = New System.Drawing.Size(220, 49)
        Me.btnExit.TabIndex = 8
        Me.btnExit.Text = "Выход"
        Me.btnExit.UseVisualStyleBackColor = True
        '
        'ListView1
        '
        Me.ListView1.Location = New System.Drawing.Point(139, 181)
        Me.ListView1.Name = "ListView1"
        Me.ListView1.Size = New System.Drawing.Size(531, 81)
        Me.ListView1.TabIndex = 9
        Me.ListView1.UseCompatibleStateImageBehavior = False
        '
        'RadioButton1
        '
        Me.RadioButton1.AutoSize = True
        Me.RadioButton1.Checked = True
        Me.RadioButton1.Location = New System.Drawing.Point(153, 232)
        Me.RadioButton1.Name = "RadioButton1"
        Me.RadioButton1.Size = New System.Drawing.Size(31, 17)
        Me.RadioButton1.TabIndex = 10
        Me.RadioButton1.TabStop = True
        Me.RadioButton1.Text = "+"
        Me.RadioButton1.UseVisualStyleBackColor = True
        '
        'RadioButton2
        '
        Me.RadioButton2.AutoSize = True
        Me.RadioButton2.Location = New System.Drawing.Point(284, 232)
        Me.RadioButton2.Name = "RadioButton2"
        Me.RadioButton2.Size = New System.Drawing.Size(28, 17)
        Me.RadioButton2.TabIndex = 11
        Me.RadioButton2.Text = "-"
        Me.RadioButton2.UseVisualStyleBackColor = True
        '
        'RadioButton3
        '
        Me.RadioButton3.AutoSize = True
        Me.RadioButton3.Location = New System.Drawing.Point(432, 232)
        Me.RadioButton3.Name = "RadioButton3"
        Me.RadioButton3.Size = New System.Drawing.Size(29, 17)
        Me.RadioButton3.TabIndex = 12
        Me.RadioButton3.Text = "*"
        Me.RadioButton3.UseVisualStyleBackColor = True
        '
        'RadioButton4
        '
        Me.RadioButton4.AutoSize = True
        Me.RadioButton4.Location = New System.Drawing.Point(563, 232)
        Me.RadioButton4.Name = "RadioButton4"
        Me.RadioButton4.Size = New System.Drawing.Size(30, 17)
        Me.RadioButton4.TabIndex = 13
        Me.RadioButton4.Text = "/"
        Me.RadioButton4.UseVisualStyleBackColor = True
        '
        'TextBox1
        '
        Me.TextBox1.Location = New System.Drawing.Point(153, 171)
        Me.TextBox1.Name = "TextBox1"
        Me.TextBox1.Size = New System.Drawing.Size(116, 20)
        Me.TextBox1.TabIndex = 14
        Me.TextBox1.Text = "ОПЕРАЦИЯ"
        '
        'TextBox2
        '
        Me.TextBox2.Location = New System.Drawing.Point(349, 337)
        Me.TextBox2.Name = "TextBox2"
        Me.TextBox2.Size = New System.Drawing.Size(124, 20)
        Me.TextBox2.TabIndex = 15
        '
        'frmFun
        '
        Me.AcceptButton = Me.btnCalculate
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.CancelButton = Me.btnClear
        Me.ClientSize = New System.Drawing.Size(877, 481)
        Me.Controls.Add(Me.TextBox2)
        Me.Controls.Add(Me.TextBox1)
        Me.Controls.Add(Me.RadioButton4)
        Me.Controls.Add(Me.RadioButton3)
        Me.Controls.Add(Me.RadioButton2)
        Me.Controls.Add(Me.RadioButton1)
        Me.Controls.Add(Me.ListView1)
        Me.Controls.Add(Me.btnExit)
        Me.Controls.Add(Me.btnClear)
        Me.Controls.Add(Me.btnCalculate)
        Me.Controls.Add(Me.lblB)
        Me.Controls.Add(Me.txtY)
        Me.Controls.Add(Me.txtX)
        Me.Controls.Add(Me.lbly)
        Me.Controls.Add(Me.lblx)
        Me.Name = "frmFun"
        Me.Text = "Функция"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents lblx As System.Windows.Forms.Label
    Friend WithEvents lbly As System.Windows.Forms.Label
    Friend WithEvents txtX As System.Windows.Forms.TextBox
    Friend WithEvents txtY As System.Windows.Forms.TextBox
    Friend WithEvents lblB As System.Windows.Forms.Label
    Friend WithEvents btnCalculate As System.Windows.Forms.Button
    Friend WithEvents btnClear As System.Windows.Forms.Button
    Friend WithEvents btnExit As System.Windows.Forms.Button
    Friend WithEvents ListView1 As System.Windows.Forms.ListView
    Friend WithEvents RadioButton1 As System.Windows.Forms.RadioButton
    Friend WithEvents RadioButton2 As System.Windows.Forms.RadioButton
    Friend WithEvents RadioButton3 As System.Windows.Forms.RadioButton
    Friend WithEvents RadioButton4 As System.Windows.Forms.RadioButton
    Friend WithEvents TextBox1 As System.Windows.Forms.TextBox
    Friend WithEvents TextBox2 As System.Windows.Forms.TextBox

End Class
