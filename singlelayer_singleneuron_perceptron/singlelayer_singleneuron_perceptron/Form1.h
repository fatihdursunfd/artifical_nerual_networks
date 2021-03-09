#pragma once
#include <math.h>

namespace CppCLRWinformsProjekt {

	// libraries 

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
		}
	protected:
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private:
		Graphics^ g;
		float current_class, e = 2.71828, x_mean, x_max, x_min, y_mean, y_max, y_min;
		int  bias = 1, c = 1, current_t;
		Boolean is_normalized = false;
		Pen^ pen1;
		Brush^ br1;
		ArrayList^ list1_y;
		ArrayList^ list1_x;
		ArrayList^ d;
		ArrayList^ errors;
		int px, py;

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ trainingToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ contiToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ continuousToolStripMenuItem;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ textBox6;


	private:
		System::ComponentModel::Container^ components;

		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->trainingToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->contiToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->continuousToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(592, 454);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(85, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"START";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->pictureBox1->Location = System::Drawing::Point(11, 27);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(550, 450);
			this->pictureBox1->TabIndex = 2;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox1_MouseClick);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"1", L"2" });
			this->comboBox1->Location = System::Drawing::Point(613, 69);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(128, 21);
			this->comboBox1->TabIndex = 3;
			this->comboBox1->Text = L"Sýnýf Seçiniz";
			this->comboBox1->SelectedValueChanged += gcnew System::EventHandler(this, &Form1::comboBox1_SelectedValueChanged);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(683, 191);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 4;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(697, 454);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(86, 23);
			this->button2->TabIndex = 6;
			this->button2->Text = L"RESET";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->trainingToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(807, 24);
			this->menuStrip1->TabIndex = 9;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// trainingToolStripMenuItem
			// 
			this->trainingToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->contiToolStripMenuItem,
					this->continuousToolStripMenuItem
			});
			this->trainingToolStripMenuItem->Name = L"trainingToolStripMenuItem";
			this->trainingToolStripMenuItem->Size = System::Drawing::Size(61, 20);
			this->trainingToolStripMenuItem->Text = L"Training";
			// 
			// contiToolStripMenuItem
			// 
			this->contiToolStripMenuItem->Name = L"contiToolStripMenuItem";
			this->contiToolStripMenuItem->Size = System::Drawing::Size(136, 22);
			this->contiToolStripMenuItem->Text = L"Discrete ";
			this->contiToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::contiToolStripMenuItem_Click);
			// 
			// continuousToolStripMenuItem
			// 
			this->continuousToolStripMenuItem->Name = L"continuousToolStripMenuItem";
			this->continuousToolStripMenuItem->Size = System::Drawing::Size(136, 22);
			this->continuousToolStripMenuItem->Text = L"Continuous";
			this->continuousToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::continuousToolStripMenuItem_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(567, 194);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(110, 13);
			this->label1->TabIndex = 10;
			this->label1->Text = L"Number of iterations : ";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(610, 220);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(57, 13);
			this->label2->TabIndex = 12;
			this->label2->Text = L"Last error :";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(683, 217);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 11;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(610, 262);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(36, 13);
			this->label3->TabIndex = 14;
			this->label3->Text = L"W[0] :";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(652, 259);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(131, 20);
			this->textBox3->TabIndex = 13;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(610, 288);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(36, 13);
			this->label4->TabIndex = 16;
			this->label4->Text = L"W[1] :";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(652, 285);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(131, 20);
			this->textBox4->TabIndex = 15;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(610, 314);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(36, 13);
			this->label5->TabIndex = 18;
			this->label5->Text = L"W[2] :";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(652, 311);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(131, 20);
			this->textBox5->TabIndex = 17;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(613, 121);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(131, 30);
			this->button3->TabIndex = 19;
			this->button3->Text = L"Normalize";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(567, 168);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(106, 13);
			this->label6->TabIndex = 21;
			this->label6->Text = L"Number of samples : ";
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(683, 165);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(100, 20);
			this->textBox6->TabIndex = 20;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(807, 541);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->Text = L"Form1";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}


	private: System::Void pictureBox1_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
	{
		if (br1)
		{
			int xCoordinate = e->X;
			int yCoordinate = e->Y;

			get_real_cords(xCoordinate, yCoordinate);

			System::Drawing::Font^ font1;
			font1 = gcnew System::Drawing::Font("Verdana", 2, FontStyle::Regular, GraphicsUnit::Millimeter);

			g->DrawString("x", font1, br1, xCoordinate, yCoordinate);
		}

	}

	void draw_coordinates_system()
	{
		this->g = pictureBox1->CreateGraphics();

		list1_x = gcnew ArrayList();
		list1_y = gcnew ArrayList();
		d = gcnew ArrayList();

		g->DrawLine(Pens::Black, 0, 225, 550, 225);
		g->DrawLine(Pens::Black, 275, 0, 275, 450);


		for (int i = 0; i < 550; i += 5)
		{
			if (i != 225)
				g->DrawLine(Pens::LightGray, 0, i, 550, i);
			if (i != 275)
				g->DrawLine(Pens::LightGray, i, 0, i, 450);

		}
	}

	void get_real_cords(int px, int py)
	{
		float rx = 0, ry = 0;

		if (px < 275 && py < 225)
		{
			rx = -(275 - px);
			ry = 225 - py;
		}
		else if (px > 275 && py < 225)
		{
			rx = px - 275;
			ry = 225 - py;
		}
		else if (px < 275 && py > 225)
		{
			rx = -(275 - px);
			ry = -(py - 225);
		}
		else if (px > 275 && py > 225)
		{
			rx = px - 275;
			ry = -(py - 225);
		}

		list1_x->Add(rx);
		list1_y->Add(ry);
		d->Add(current_class);

	}

	private: System::Void comboBox1_SelectedValueChanged(System::Object^ sender, System::EventArgs^ e) {

		if (comboBox1->SelectedItem->ToString() == "1")
		{
			br1 = Brushes::Blue;
			current_class = 1;

		}

		else if (comboBox1->SelectedItem->ToString() == "2")
		{
			br1 = Brushes::Red;
			current_class = -1;
		}

	}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		/// draw coordinates system 
		draw_coordinates_system();
	}

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e)
	{
		//Reset the screen

		is_normalized = false;

		list1_x->Clear();
		list1_y->Clear();
		d->Clear();

		textBox1->Clear();
		textBox2->Clear();
		textBox6->Clear();

		pictureBox1->Refresh();
		draw_coordinates_system();

	}

	void get_picturebox_cords(int rx, int ry)
	{
		px = 0, py = 0;

		if (rx < 0 && ry > 0)
		{
			px = 275 + rx;
			py = 225 - ry;
		}
		else if (rx > 0 && ry > 0)
		{
			px = 275 + rx;
			py = 225 - ry;
		}
		else if (rx < 0 && ry < 0)
		{
			px = 275 + rx;
			py = 225 - ry;
		}
		else if (rx > 0 && ry < 0)
		{
			px = 275 + rx;
			py = 225 - ry;
		}
	}

	float sigmoid(float net)
	{
		float s = 0;
		s = 2 / (1 + exp(-net)) - 1;
		return s;
	}

	int signum(float net)
	{
		if (net > 0)
			return 1;
		else if (net == 0)
			return 0;
		else
			return -1;
	}

	void drawline(float w[3])
	{
		//draw the first line
		int sy, fy, sx, fx;

		if (w[0] == 0)
		{
			sx = -275;
			fx = 275;
			sy = -(w[2] / w[1]);
			fy = -(w[2] / w[1]);
		}
		else if (w[1] == 0)
		{
			sx = -(w[2] / w[0]);
			fx = -(w[2] / w[0]);
			sy = -225;
			fy = 225;
		}
		else
		{
			sx = -275;
			fx = 275;
			sy = -(w[0] * -275 + w[2]) / w[1];
			fy = -(w[0] * 275 + w[2]) / w[1];
		}


		get_picturebox_cords(sx, sy);
		sx = px;
		sy = py;
		get_picturebox_cords(fx, fy);
		fx = px;
		fy = py;


		//g->DrawLine(Pens::Red, px1, py1, px2, py2);
		if (current_t == 1)
			g->DrawLine(Pens::DarkMagenta, sx, sy, fx, fy);
		else if (current_t == 2)
			g->DrawLine(Pens::Green, sx, sy, fx, fy);
	}

	float dot_product(float w[3], float samples[3])
	{
		float dp = 0;
		for (int i = 0; i < 3; i++)
		{
			dp += w[i] * samples[i];
		}

		return dp;
	}

	//single layer discrete perceptron
	private: System::Void contiToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		textBox6->Text = list1_x->Count.ToString();
		current_t = 2;
		//initialize the weights
		float w[3] = { 1,1,10 };

		//drawline(w);

		int number_of_iterations = 0;
		float net, fnet, delta_w, error = 1;

		while (error != 0)
		{
			error = 0;

			IEnumerator^ myEnum1 = list1_x->GetEnumerator();
			IEnumerator^ myEnum2 = list1_y->GetEnumerator();
			IEnumerator^ myEnum3 = d->GetEnumerator();

			for (int i = 0; i < (int)list1_x->Count; i++)
			{
				myEnum1->MoveNext();
				myEnum2->MoveNext();
				myEnum3->MoveNext();

				Object^ obj1 = safe_cast<Object^>(myEnum1->Current);
				Object^ obj2 = safe_cast<Object^>(myEnum2->Current);
				Object^ obj3 = safe_cast<Object^>(myEnum3->Current);

				float x1 = (float)obj1;
				float y1 = (float)obj2;
				float d = (float)obj3;

				float samples[3] = { x1, y1 , bias };

				net = dot_product(w, samples);
				fnet = signum(net);

				delta_w = 0.5 * c * (d - fnet) ;

				float deltaw[3] = { samples[0] * delta_w ,samples[1] * delta_w,samples[2] * delta_w };

				error += 0.5 * (d - fnet) * (d - fnet);

				w[0] = w[0] + deltaw[0];
				w[1] = w[1] + deltaw[1];
				w[2] = w[2] + deltaw[2];

			}
			number_of_iterations++;
		}

		textBox1->Text = number_of_iterations.ToString();
		textBox2->Text = error.ToString();

		textBox3->Text = w[0].ToString();
		textBox4->Text = w[1].ToString();
		textBox5->Text = w[2].ToString();

		drawline(w);


	}

		   //single layer continuous perceptron
	private: System::Void continuousToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		textBox6->Text = list1_x->Count.ToString();
		current_t = 1;
		//initialize the weights
		float w[3] = { 0.01,0.11,0.02 };

		//drawline(w);

		int number_of_iterations = 0;
		float net, fnet, delta_w, error = 1, max_error = 0.001;

		while (error > max_error)
		{
			error = 0;

			IEnumerator^ myEnum1 = list1_x->GetEnumerator();
			IEnumerator^ myEnum2 = list1_y->GetEnumerator();
			IEnumerator^ myEnum3 = d->GetEnumerator();

			for (int i = 0; i < (int)list1_x->Count; i++)
			{
				myEnum1->MoveNext();
				myEnum2->MoveNext();
				myEnum3->MoveNext();

				Object^ obj1 = safe_cast<Object^>(myEnum1->Current);
				Object^ obj2 = safe_cast<Object^>(myEnum2->Current);
				Object^ obj3 = safe_cast<Object^>(myEnum3->Current);

				float x1 = (float)obj1;
				float y1 = (float)obj2;
				float d = (float)obj3;

				float samples[3] = { x1, y1 , bias };

				if (is_normalized == true)
				{
					normalize();
					normalization(samples);
				}
				

				net = dot_product(w, samples);
				fnet = sigmoid(net);

				delta_w = 0.5 * c * (d - fnet);

				float deltaw[3] = { samples[0] * delta_w ,samples[1] * delta_w,samples[2] * delta_w };

				error += 0.5 * (d - fnet) * (d - fnet);

				w[0] = w[0] + deltaw[0];
				w[1] = w[1] + deltaw[1];
				w[2] = w[2] + deltaw[2];

			}

			number_of_iterations++;
		}

		textBox1->Text = number_of_iterations.ToString();
		textBox2->Text = error.ToString();

		textBox3->Text = w[0].ToString();
		textBox4->Text = w[1].ToString();
		textBox5->Text = w[2].ToString();


		drawline(w);
	}

	void normalize()
	{
		// calculate mean
		// find max and min 

		IEnumerator^ myEnum1 = list1_x->GetEnumerator();
		IEnumerator^ myEnum2 = list1_y->GetEnumerator();

		float x_sum = 0, y_sum = 0;

		myEnum1->MoveNext();
		myEnum2->MoveNext();

		Object^ obj1 = safe_cast<Object^>(myEnum1->Current);
		Object^ obj2 = safe_cast<Object^>(myEnum2->Current);

		float x1 = (float)obj1;
		float y1 = (float)obj2;

		x_sum += x1;
		y_sum += y1;
		x_max = x1;
		x_min = x1;
		y_max = y1;
		y_min = y1;

		for (int i = 0; i < (int)list1_x->Count-1; i++)
		{
			myEnum1->MoveNext();
			myEnum2->MoveNext();

			Object^ obj1 = safe_cast<Object^>(myEnum1->Current);
			Object^ obj2 = safe_cast<Object^>(myEnum2->Current);

			float x1 = (float)obj1;
			float y1 = (float)obj2;

			if (x1 > x_max)
				x_max = x1;
			if (x1 < x_min)
				x_min = x1;

			if (y1 > y_max)
				y_max = y1;
			if (y1 < y_min)
				y_min = y1;

			x_sum += x1;
			y_sum += y1;
		}

		x_mean = x_sum / (int)list1_x->Count;
		y_mean = y_sum / (int)list1_y->Count;

	}

	void normalization(float* samples)
	{

		//float norm = sqrt(samples[0] * samples[0] + samples[1] * samples[1] + samples[2] * samples[2]);
		//samples[0] = samples[0] / norm;
		//samples[1] = samples[1] / norm;
		//samples[2] = samples[2] / norm;

		// x = x- xmean / xmax - xmin
		// y = y- ymean / ymax - ymin

		samples[0] = 150 * (samples[0] - x_mean) / (x_max - x_min);
		samples[1] = 150 * (samples[1] - y_mean) / (y_max - y_min);

	}
	// normalized data and draw
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e)
	{
		is_normalized = true;

		pictureBox1->Refresh();
		this->g = pictureBox1->CreateGraphics();

		g->DrawLine(Pens::Black, 0, 225, 550, 225);
		g->DrawLine(Pens::Black, 275, 0, 275, 450);


		for (int i = 0; i < 550; i += 5)
		{
			if (i != 225)
				g->DrawLine(Pens::LightGray, 0, i, 550, i);
			if (i != 275)
				g->DrawLine(Pens::LightGray, i, 0, i, 450);

		}

		IEnumerator^ myEnum1 = list1_x->GetEnumerator();
		IEnumerator^ myEnum2 = list1_y->GetEnumerator();
		IEnumerator^ myEnum3 = d->GetEnumerator();

		for (int i = 0; i < (int)list1_x->Count; i++)
		{
			myEnum1->MoveNext();
			myEnum2->MoveNext();
			myEnum3->MoveNext();

			Object^ obj1 = safe_cast<Object^>(myEnum1->Current);
			Object^ obj2 = safe_cast<Object^>(myEnum2->Current);
			Object^ obj3 = safe_cast<Object^>(myEnum3->Current);

			float x1 = (float)obj1;
			float y1 = (float)obj2;
			float d = (float)obj3;

			if (d == 1)
				br1 = Brushes::Blue;
			else
				br1 = Brushes::Red;


			float samples[3] = { x1, y1 , bias };
			normalize();
			normalization(samples);

			

			System::Drawing::Font^ font1;
			font1 = gcnew System::Drawing::Font("Verdana", 1, FontStyle::Regular, GraphicsUnit::Millimeter);
			get_picturebox_cords(samples[0], samples[1]);
			g->DrawString("x", font1, br1, px, py);

		}


	}


};
}
