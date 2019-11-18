namespace WindowsFormsApp1
{
    partial class ViewForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
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
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(ViewForm));
            this.studentLabel = new System.Windows.Forms.Label();
            this.markLabel = new System.Windows.Forms.Label();
            this.q1Label = new System.Windows.Forms.Label();
            this.q3Label = new System.Windows.Forms.Label();
            this.q2Label = new System.Windows.Forms.Label();
            this.closeButton = new System.Windows.Forms.Button();
            this.dateLabel = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // studentLabel
            // 
            this.studentLabel.AutoSize = true;
            this.studentLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.studentLabel.Location = new System.Drawing.Point(12, 9);
            this.studentLabel.Name = "studentLabel";
            this.studentLabel.Size = new System.Drawing.Size(69, 18);
            this.studentLabel.TabIndex = 1;
            this.studentLabel.Text = "Студент:";
            // 
            // markLabel
            // 
            this.markLabel.AutoSize = true;
            this.markLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.markLabel.Location = new System.Drawing.Point(12, 40);
            this.markLabel.Name = "markLabel";
            this.markLabel.Size = new System.Drawing.Size(64, 18);
            this.markLabel.TabIndex = 2;
            this.markLabel.Text = "Оценка:";
            // 
            // q1Label
            // 
            this.q1Label.AutoSize = true;
            this.q1Label.Font = new System.Drawing.Font("Microsoft Sans Serif", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.q1Label.Location = new System.Drawing.Point(12, 113);
            this.q1Label.Name = "q1Label";
            this.q1Label.Size = new System.Drawing.Size(76, 18);
            this.q1Label.TabIndex = 3;
            this.q1Label.Text = "Вопрос 1:";
            // 
            // q3Label
            // 
            this.q3Label.AutoSize = true;
            this.q3Label.Font = new System.Drawing.Font("Microsoft Sans Serif", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.q3Label.Location = new System.Drawing.Point(12, 175);
            this.q3Label.Name = "q3Label";
            this.q3Label.Size = new System.Drawing.Size(76, 18);
            this.q3Label.TabIndex = 4;
            this.q3Label.Text = "Вопрос 3:";
            // 
            // q2Label
            // 
            this.q2Label.AutoSize = true;
            this.q2Label.Font = new System.Drawing.Font("Microsoft Sans Serif", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.q2Label.Location = new System.Drawing.Point(12, 144);
            this.q2Label.Name = "q2Label";
            this.q2Label.Size = new System.Drawing.Size(76, 18);
            this.q2Label.TabIndex = 5;
            this.q2Label.Text = "Вопрос 2:";
            // 
            // closeButton
            // 
            this.closeButton.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.closeButton.Location = new System.Drawing.Point(100, 231);
            this.closeButton.Name = "closeButton";
            this.closeButton.Size = new System.Drawing.Size(109, 34);
            this.closeButton.TabIndex = 13;
            this.closeButton.Text = "Закрыть";
            this.closeButton.UseVisualStyleBackColor = true;
            this.closeButton.Click += new System.EventHandler(this.closeButton_Click);
            // 
            // dateLabel
            // 
            this.dateLabel.AutoSize = true;
            this.dateLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.dateLabel.Location = new System.Drawing.Point(12, 71);
            this.dateLabel.Name = "dateLabel";
            this.dateLabel.Size = new System.Drawing.Size(47, 18);
            this.dateLabel.TabIndex = 14;
            this.dateLabel.Text = "Дата:";
            // 
            // ViewForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.ClientSize = new System.Drawing.Size(308, 277);
            this.Controls.Add(this.dateLabel);
            this.Controls.Add(this.closeButton);
            this.Controls.Add(this.q2Label);
            this.Controls.Add(this.q3Label);
            this.Controls.Add(this.q1Label);
            this.Controls.Add(this.markLabel);
            this.Controls.Add(this.studentLabel);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MaximizeBox = false;
            this.Name = "ViewForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Просмотр";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label studentLabel;
        private System.Windows.Forms.Label markLabel;
        private System.Windows.Forms.Label q1Label;
        private System.Windows.Forms.Label q3Label;
        private System.Windows.Forms.Label q2Label;
        private System.Windows.Forms.Button closeButton;
        private System.Windows.Forms.Label dateLabel;
    }
}