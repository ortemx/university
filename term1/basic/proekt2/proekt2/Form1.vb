
Public Class frmFun
    Private Sub btnCalculate_Click(sender As System.Object, e As System.EventArgs) Handles btnCalculate.Click
        Dim a As Single, b As Single, x As Single, y As Single
        If txtA.Text = "" Then
            txtA.Focus()
            MsgBox("Введите A", vbExclamation, "Ошибка ввода")
        ElseIf IsNumeric(txtA.Text) = False Then
            txtA.Focus()
            txtA.Text = ""
            MsgBox("Введите число", vbExclamation, "Ошибка ввода")
        ElseIf txtB.Text = "" Then
            txtB.Focus()
            MsgBox("Введите B", vbExclamation, "Ошибка ввода")
        ElseIf IsNumeric(txtB.Text) = False Then
            txtB.Focus()
            txtB.Text = ""
            MsgBox("Введите чиcло", vbExclamation, "Ошибка ввода")
        ElseIf txtX.Text = "" Then
            txtX.Focus()
            MsgBox("Введите X", vbExclamation, "Ошибка ввода")
        ElseIf IsNumeric(txtX.Text) = False Then
            txtX.Focus()
            txtX.Text = ""
            MsgBox("Введите число", vbExclamation, "Ошибка ввода")

        Else
            a = txtA.Text
            b = txtB.Text
            x = txtX.Text


            y = ((x + 1) * x ^ 2) / b - Math.Sin(x + a) ^ 2
            lblFunY.Text = Format(b, "0.000")
            txtA.Enabled = False
            txtB.Enabled = False
            txtX.Enabled = False
        End If
        Exit Sub

    End Sub

    Private Sub btnClear_Click(sender As System.Object, e As System.EventArgs) Handles btnClear.Click
        txtA.Enabled = True
        txtB.Enabled = True
        txtX.Enabled = True
        txtA.Text = ""
        txtB.Text = ""
        txtX.Text = ""
        txtX.Focus()
        lblFunY.Text = ""

    End Sub


    Private Sub btnExit_Click(sender As System.Object, e As System.EventArgs) Handles btnExit.Click
        End

    End Sub

    Private Sub txtA_TextChanged(sender As System.Object, e As System.EventArgs) Handles txtA.TextChanged

    End Sub
End Class
