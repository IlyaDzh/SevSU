Public Class Form1
    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles Button1.Click
        If TextBox1.Text = "" Or TextBox2.Text = "" Then
            MessageBox.Show("Поле пустое", "Ошибка!")
        Else
            Label2.Text = Convert.ToInt32(TextBox1.Text) + Convert.ToInt32(TextBox2.Text)
        End If
    End Sub

    Private Sub Button2_Click(sender As Object, e As EventArgs) Handles Button2.Click
        If TextBox3.Text = "" Or TextBox4.Text = "" Then
            MessageBox.Show("Поле пустое", "Ошибка!")
        Else
            Label3.Text = Convert.ToInt32(TextBox4.Text) - Convert.ToInt32(TextBox3.Text)
        End If
    End Sub
End Class