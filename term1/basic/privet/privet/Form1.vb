Public Class frmHello

    Private Sub cmdExit_Click(sender As System.Object, e As System.EventArgs) Handles btnExit.Click
        End

    End Sub

    Private Sub cmdHello_Click(sender As System.Object, e As System.EventArgs) Handles btnHello.Click
        lblHello.Text = "Приветэ"




    End Sub

    Private Sub cmdClear_Click(sender As System.Object, e As System.EventArgs) Handles btnClear.Click
        lblHello.Text = ""
    End Sub
End Class
