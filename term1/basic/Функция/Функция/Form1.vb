Public Class frmFun
    Private Sub btnCalculate_Click(sender As System.Object, e As System.EventArgs) Handles btnCalculate.Click
        Dim x As Single, y As Single, b As Single
        If txtX.Text = "" Then
            txtX.Focus()
            MsgBox("Введите X", vbExclamation, "Ошибка ввода")
        ElseIf IsNumeric(txtX.Text) = False Then
            txtX.Focus()
            txtX.Text = ""
            MsgBox("Введите число", vbExclamation, "Ошибка ввода")
        ElseIf txtY.Text = "" Then
            txtY.Focus()
            MsgBox("Введите Y", vbExclamation, "Ошибка ввода")
        ElseIf IsNumeric(txtY.Text) = False Then
            txtY.Focus()
            txtY.Text = ""
            MsgBox("Введите чиcло", vbExclamation, "Ошибка ввода")
        Else
            X = txtX.Text
            Y = txtY.Text

            b = Math.Abs(x ^ (y / x) - (y / x) ^ (1 / 3))
            lblFunB.Text = Format(B, "0.000")
            txtX.Enabled = False
            txtY.Enabled = False
        End If
        Exit Sub
        MsgBox("Аргумент(-ы) не из бласти определения", vbCritical,
            "Ошибка")
        txtY.Focus()
    End Sub

    Private Sub btnClear_Click(sender As System.Object, e As System.EventArgs) Handles btnClear.Click
        txtX.Enabled = True
        txtY.Enabled = True
        txtX.Text = ""
        txtY.Text = ""
        txtX.Focus()
        lblFunB.Text = ""
    End Sub

    Private Sub btnExit_Click(sender As System.Object, e As System.EventArgs) Handles btnExit.Click
        End
    End Sub
End Class
