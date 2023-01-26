Public Class Form1
    Private mypoint1 As Boolean, mypoint2 As Boolean
    Sub MySub(ByRef c As Char, ByVal t As TextBox, ByRef mypoint As Boolean)
        Select Case c
            Case "-", "+"
                If t.Text <> "" Then c = ""
            Case ","
                If mypoint = False Then mypoint = True Else c = ""
            Case "0" To "9"
            Case Else
                c = ""
        End Select
    End Sub
    Private Sub Button1_Click(sender As System.Object, e As System.EventArgs) Handles Button1.Click
        Dim c As Single, d As Single
        If A.Text = "" Then
            A.Focus()
            MsgBox("Введите а", vbExclamation, "Ошибка ввода")
        ElseIf B.Text = "" Then
            B.Focus()
            MsgBox("Введите b", vbExclamation, "Ошибка ввода")
        End If
        c = Val(A.Text)
        d = Val(B.Text)
        Select Case True
            Case RadioButton1.Checked
                Rez.Text = Format(c + d, "0.000")
            Case RadioButton2.Checked
                Rez.Text = Format(c - d, "0.000")
            Case RadioButton3.Checked
                Rez.Text = Format(c * d, "0.000")
            Case RadioButton4.Checked
                If d = 0 Then
                    B.Focus()
                    MsgBox("Деление на 0", vbExclamation, "Ошибка ввода")
                Else : Rez.Text = Format(c / d)
                End If
        End Select
        A.Enabled = False
        B.Enabled = False
        Rez.Enabled = False

    End Sub

    Private Sub A_KeyPress(ByVal sender As Object, ByVal e As System.Windows.Forms.KeyPressEventArgs) Handles A.KeyPress
        Call MySub(e.KeyChar, A, mypoint1)
    End Sub

    Private Sub B_KeyPress(ByVal sender As Object, ByVal e As System.Windows.Forms.KeyPressEventArgs) Handles B.KeyPress
        Call MySub(e.KeyChar, B, mypoint2)
    End Sub

    Private Sub Button2_Click(sender As System.Object, e As System.EventArgs) Handles Button2.Click
        A.Enabled = True
        B.Enabled = True
        Rez.Enabled = True
        RadioButton1.Checked = True
        A.Text = ""
        B.Text = ""
        Rez.Text = ""
        A.Focus()
        mypoint1 = False
        mypoint2 = False

    End Sub

    Private Sub Button3_Click(sender As System.Object, e As System.EventArgs) Handles Button3.Click
        End
    End Sub

    Private Sub Form1_Load(sender As System.Object, e As System.EventArgs) Handles MyBase.Load

    End Sub
End Class
