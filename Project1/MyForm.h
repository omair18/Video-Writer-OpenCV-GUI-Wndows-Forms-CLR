#pragma once
#include "player.h"
#include <stdio.h>
#include <time.h>
#include <ctime>
//#include <msclr\marshal_cppstd.h>
namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Configuration;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog2;
	//private: char codec_string[5] = "H264";
	private: int codec;
	private: cv::VideoCapture *capture;
	private: cv::VideoWriter* video_write;
	private: System::String^ url_path;
	private: System::String^ saveto_path;
	private: System::String^ initial_saveto_path;

	private: bool stop;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;
	private: int frame_width;
	private: int frame_height;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::TextBox^  textBox2;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>

		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->saveFileDialog2 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(16, 28);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(82, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"VIDEO URL";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(161, 28);
			this->textBox1->Margin = System::Windows::Forms::Padding(4);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(200, 22);
			this->textBox1->TabIndex = 1;
			this->textBox1->Text = L"add url";
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(20, 66);
			this->button1->Margin = System::Windows::Forms::Padding(4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(100, 28);
			this->button1->TabIndex = 2;
			this->button1->Text = L"SaveTo";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::ForestGreen;
			this->button2->Enabled = false;
			this->button2->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->button2->Location = System::Drawing::Point(20, 157);
			this->button2->Margin = System::Windows::Forms::Padding(4);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(100, 28);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Start";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->button3->Enabled = false;
			this->button3->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->button3->Location = System::Drawing::Point(19, 193);
			this->button3->Margin = System::Windows::Forms::Padding(4);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(100, 28);
			this->button3->TabIndex = 4;
			this->button3->Text = L"Stop";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(161, 78);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(0, 17);
			this->label2->TabIndex = 5;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(161, 76);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(87, 17);
			this->label3->TabIndex = 6;
			this->label3->Text = L"<save-path>";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(268, 163);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(0, 17);
			this->label4->TabIndex = 7;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(148, 163);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(112, 17);
			this->label5->TabIndex = 8;
			this->label5->Text = L"Frames Written: ";
			this->label5->Click += gcnew System::EventHandler(this, &MyForm::label5_Click);
			// 
			// backgroundWorker1
			// 
			this->backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MyForm::backgroundWorker1_DoWork);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(148, 199);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(137, 17);
			this->label6->TabIndex = 9;
			this->label6->Text = L"Time Passed (mins):";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(268, 199);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(0, 17);
			this->label7->TabIndex = 10;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(17, 108);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(116, 17);
			this->label8->TabIndex = 11;
			this->label8->Text = L"Chunk size(mins)";
			this->label8->Click += gcnew System::EventHandler(this, &MyForm::label8_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(160, 108);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 22);
			this->textBox2->TabIndex = 12;
			this->textBox2->Text = L"30";
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(739, 425);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		this->button3->Enabled = false;
		this->button2->Enabled = true;

		SaveFileDialog ^ saveFileDialog1 = gcnew SaveFileDialog();
		saveFileDialog1->Filter = "Video file (*.avi)|*.avi";
		saveFileDialog1->Title = "Save a video file";

		//CODE REQUIRED TO SAVE s2 AS .TXT FILE

		saveFileDialog1->ShowDialog();
		this->saveto_path = saveFileDialog1->FileName;
		array<String^> ^StringArray = this->saveto_path->Split('.');
		System::DateTime^ current_time = System::DateTime::Now;

		time_t rawtime;
		struct tm * timeinfo;
		char buffer[80];

		time(&rawtime);
		timeinfo = localtime(&rawtime);

		strftime(buffer, sizeof(buffer), "_%d-%m-%Y_%H_%M_%S.", timeinfo);
		std::string str(buffer);
		String ^datetime = gcnew String(str.c_str());
		this->url_path = textBox1->Text;
		this->initial_saveto_path = StringArray[0];

		this->saveto_path = StringArray[0] + datetime + StringArray[1];
		label3->Text = saveto_path;//datetime; //this->saveto_path;
		stop = false;
		//label3->Text = path;
	}
private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	
}
Void MarshalString(String ^ s, std::string& os) {
			 using namespace Runtime::InteropServices;
			 const char* chars =
				 (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
			 os = chars;
			 Marshal::FreeHGlobal(IntPtr((void*)chars));
		 }

private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {

	//msclr::interop::marshal_context context;
	this->button1->Enabled = false;
	this->button2->Enabled = false;
	this->button3->Enabled = true;
	std::string url;
	MarshalString(this->url_path, url);
	this->capture = new cv::VideoCapture();
	this->capture->open(url);
	if (this->capture->isOpened()) {
		this->frame_width = this->capture->get(cv::CAP_PROP_FRAME_WIDTH);
		this->frame_height = this->capture->get(cv::CAP_PROP_FRAME_HEIGHT);
		this->codec = cv::VideoWriter::fourcc('H','2','6','4');
		//this->codec = cv::VideoWriter::fourcc('X','V','I','D');
		std::string path;//this->saveto_path->ToString;//context.marshal_as<std::string>(this->saveto_path);
		MarshalString(this->saveto_path, path);
		this->video_write = new cv::VideoWriter(path, this->codec, 25, cv::Size(this->frame_width, this->frame_height));
		backgroundWorker1->WorkerSupportsCancellation = true;
		backgroundWorker1->RunWorkerAsync(1);
	}

}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) { //stop button
	this->stop = true;
	backgroundWorker1->CancelAsync();
	this->capture->release();
	this->video_write->release();
	this->button1->Enabled = true;
	this->button2->Enabled = false;


}
private: System::Void label5_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void backgroundWorker1_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {
	
	System::DateTime^ current_time = System::DateTime::Now;
	time_t start = time(0);
	double seconds_since_start;
	cv::Mat frame;
	int num_frames = 0;
	String^ chunk_size = textBox2->Text;
	int chunk_time = System::Convert::ToInt16(chunk_size);
	while (!this->stop)
	{
		seconds_since_start= difftime(time(0), start);
		if (seconds_since_start / 60 == chunk_time) { // if 30minutes have passed
			this->video_write->release();
			//make new file path; 
			array<String^> ^StringArray = this->saveto_path->Split('.');
			System::DateTime^ current_time = System::DateTime::Now;

			time_t rawtime;
			struct tm * timeinfo;
			char buffer[80];

			time(&rawtime);
			timeinfo = localtime(&rawtime);

			strftime(buffer, sizeof(buffer), "_%d-%m-%Y_%H_%M_%S.", timeinfo);
			std::string str(buffer);
			String ^datetime = gcnew String(str.c_str());
			this->saveto_path = this->initial_saveto_path + datetime + StringArray[1];
			std::string path;
			MarshalString(this->saveto_path, path);
			label3->Text = saveto_path;
			this->video_write = new cv::VideoWriter(path, codec, 25, cv::Size(frame_width, frame_height));
			start = time(0);
			//break;
		}
		if (!this->capture->read(frame))
		{
			this->stop = true;
			//this->stop = true;
			this->capture->release();
			this->video_write->release();
			this->button1->Enabled = true;
			this->button2->Enabled = false;
		}
		if (!frame.empty() && frame.channels() == 3) {
			this->video_write->write(frame);
			num_frames++;
			label4->Text = System::Convert::ToString(num_frames);
			label7->Text = System::Convert::ToString(seconds_since_start);
			//cv::cvtColor(frame, RGBframe, cv::COLOR_BGR2RGB);
			//img = QImage((const unsigned char*)(RGBframe.data), RGBframe.cols,RGBframe.rows,QImage::Format_RGB888);
		}
		else
		{
			this->stop = true;
			this->capture->release();
			this->video_write->release();
			this->button1->Enabled = true;
			this->button1->Enabled = true;
			this->button2->Enabled = false;
			//img = QImage((const unsigned char*)(frame.data), frame.cols,frame.rows,QImage::Format_Indexed8);
		}
		//emit processedImage(img);
		//this->msleep(delay);
	}
	this->stop = true;
	this->capture->release();
	this->video_write->release();
	this->button1->Enabled = true;
	this->button2->Enabled = false;

}
private: System::Void label8_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
}
};
}
