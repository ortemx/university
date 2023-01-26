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
        Me.lblFunB = New System.Windows.Forms.Label()
        Me.btnCalculate = New System.Windows.Forms.Button()
        Me.btnClear = New System.Windows.Forms.Button()
        Me.btnExit = New System.Windows.Forms.Button()
        Me.SuspendLayout()
        '
        'lblx
        '
        Me.lblx.AutoSize = True
        Me.lblx.Location = New System.Drawing.Point(14, 46)
        Me.lblx.Name = "lblx"
        Me.lblx.Size = New System.Drawing.Size(18, 13)
        Me.lblx.TabIndex = 0
        Me.lblx.Text = "x="
        Me.lblx.TextAlign = System.Drawing.ContentAlignment.TopRight
        '
        'lbly
        '
        Me.lbly.AutoSize = True
        Me.lbly.Location = New System.Drawing.Point(109, 46)
        Me.lbly.Name = "lbly"
        Me.lbly.Size = New System.Drawing.Size(18, 13)
        Me.lbly.TabIndex = 1
        Me.lbly.Text = "y="
        Me.lbly.TextAlign = System.Drawing.ContentAlignment.TopRight
        '
        'txtX
        '
        Me.txtX.Location = New System.Drawing.Point(38, 43)
        Me.txtX.Name = "txtX"
        Me.txtX.Size = New System.Drawing.Size(26, 20)
        Me.txtX.TabIndex = 0
        '
        'txtY
        '
        Me.txtY.Location = New System.Drawing.Point(133, 43)
        Me.txtY.Name = "txtY"
        Me.txtY.Size = New System.Drawing.Size(34, 20)
        Me.txtY.TabIndex = 1
        '
        'lblB
        '
        Me.lblB.AutoSize = True
        Me.lblB.Location = New System.Drawing.Point(77, 120)
        Me.lblB.Name = "lblB"
        Me.lblB.Size = New System.Drawing.Size(19, 13)
        Me.lblB.TabIndex = 4
        Me.lblB.Text = "b="
        Me.lblB.TextAlign = System.Drawing.ContentAlignment.TopRight
        '
        'lblFunB
        '
        Me.lblFunB.AutoSize = True
        Me.lblFunB.BackColor = System.Drawing.SystemColors.ControlLightLight
        Me.lblFunB.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle
        Me.lblFunB.Location = New System.Drawing.Point(102, 118)
        Me.lblFunB.Name = "lblFunB"
        Me.lblFunB.Size = New System.Drawing.Size(2, 15)
        Me.lblFunB.TabIndex = 5
        '
        'btnCalculate
        '
        Me.btnCalculate.Location = New System.Drawing.Point(185, 12)
        Me.btnCalculate.Name = "btnCalculate"
        Me.btnCalculate.Size = New System.Drawing.Size(140, 51)
        Me.btnCalculate.TabIndex = 6
        Me.btnCalculate.Text = "Вычислить"
        Me.btnCalculate.UseVisualStyleBackColor = True
        '
        'btnClear
        '
        Me.btnClear.DialogResult = System.Windows.Forms.DialogResult.Cancel
        Me.btnClear.Location = New System.Drawing.Point(185, 83)
        Me.btnClear.Name = "btnClear"
        Me.btnClear.Size = New System.Drawing.Size(140, 48)
        Me.btnClear.TabIndex = 7
        Me.btnClear.Text = "Сброс"
        Me.btnClear.UseVisualStyleBackColor = True
        '
        'btnExit
        '
        Me.btnExit.DialogResult = System.Windows.Forms.DialogResult.Cancel
        Me.btnExit.Location = New System.Drawing.Point(185, 154)
        Me.btnExit.Name = "btnExit"
        Me.btnExit.Size = New System.Drawing.Size(140, 49)
        Me.btnExit.TabIndex = 8
        Me.btnExit.Text = "Выход"
        Me.btnExit.UseVisualStyleBackColor = True
        '
        'frmFun
        '
        Me.AcceptButton = Me.btnCalculate
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.CancelButton = Me.btnClear
        Me.ClientSize = New System.Drawing.Size(349, 250)
        Me.Controls.Add(Me.btnExit)
        Me.Controls.Add(Me.btnClear)
        Me.Controls.Add(Me.btnCalculate)
        Me.Controls.Add(Me.lblFunB)
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
    Friend WithEvents lblFunB As System.Windows.Forms.Label
    Friend WithEvents btnCalculate As System.Windows.Forms.Button
    Friend WithEvents btnClear As System.Windows.Forms.Button
    Friend WithEvents btnExit As System.Windows.Forms.Button

End Class
