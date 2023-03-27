#pragma once

#include "Shape.h"
#include "Triangle.h"
#include "Vertex.h"
#include "Sphere.h"
#include <vector>

#ifndef _MYFORM_H
#define _MYFORM_H


	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;

	/// <summary>
	/// MyForm için özet
	/// </summary>
	/// 

	struct intersections // basic struct
	{
		float distance; //  represent t distances
		int   indice; //to keep shape array index
	} intersection;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Oluþturucu kodunu buraya ekle
			//
		}

	protected:
		/// <summary>
		///Kullanýlan tüm kaynaklarý temizleyin.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	protected:
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button2;

	private:
		/// <summary>
		///Gerekli tasarýmcý deðiþkeni.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Tasarýmcý desteði için gerekli metot - bu metodun 
		///içeriðini kod düzenleyici ile deðiþtirmeyin.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(2, 2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(1058, 565);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(327, 603);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(234, 40);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Create Triangles";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::createTriangles);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 621);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(149, 17);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Rendering Time (sec.)";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(191, 621);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 22);
			this->textBox1->TabIndex = 3;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(567, 603);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(234, 39);
			this->button2->TabIndex = 4;
			this->button2->Text = L"Create Spheres";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::createSpheres);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1072, 647);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		Color TraceRayTri(Vertex Ro, Vertex Rd, Shape* Shapes[])
		{
			std::vector <intersections> Intersections;//vector array

			for (int i = 0; i < 3; i++) // three triangle 
			{
				float t = Shapes[i]->Intersect(Ro, Rd); // t is come intersect test

				if (t > 0.0F)// there is a intersect
				{
					
					intersection.distance = t;
					intersection.indice = i;

					Intersections.push_back(intersection); 

					//Vertex iPoint = Ro + t * Rd;

				
				}
			}

			if (Intersections.size() > 0)// if there are many intersect
			{
				float min_distance = FLT_MAX; // //we need to min t 
				int   min_indis = -1;

				for (int i = 0; i < Intersections.size(); i++)
				{
					if (Intersections[i].distance < min_distance)
					{
						min_indis = Intersections[i].indice;
						min_distance = Intersections[i].distance;
					}
				}

				

				return Shapes[min_indis]->shapeColor;// min t which has triangle color
			}

			return Color::Black;// if there is no instersect returns black
		}

		Color TraceRaySphere(Vertex Ro, Vertex Rd, Shape* Shapes[])
		{
			std::vector<intersections> Intersections;

			for (int i = 0; i < 1; i++)//one spehere
			{
				float t = Shapes[i]->Intersect(Ro, Rd);

				if (t > 0.0F)
				{
					intersection.distance = t;
					intersection.indice = i;

					Intersections.push_back(intersection);

					//Vertex iPoint(intersectionPoint) = Ro + t * Rd;  // first contact point with sphere and ray

				}
			}

			if (Intersections.size() > 0)
			{
				float min_distance = FLT_MAX;
				int   min_indis = -1;

				for (int i = 0; i < Intersections.size(); i++)
				{
					if (Intersections[i].distance < min_distance)
					{
						min_indis = Intersections[i].indice;
						min_distance = Intersections[i].distance;
					}
				}

				return Shapes[min_indis]->shapeColor;
			}

			return Color::Black;
		}


	private: System::Void createTriangles(System::Object^ sender, System::EventArgs^ e) {


		DateTime startTime;
		startTime = startTime.Now;

		Bitmap^ surface = gcnew Bitmap(800, 450);// 16:9 
		pictureBox1->Image = surface;

		
		Triangle T1(Vertex(0, 30, 40), Vertex(40, -30, 120), Vertex(-40, -30, 120), Color::Red);
		Triangle T2(Vertex(-50, 30, 124), Vertex(50, 30, 124), Vertex(0, -30, 44), Color::Green);
		Triangle T3(Vertex(-30, 0, 37), Vertex(30, 40, 117), Vertex(30, -40, 117), Color::Blue);

		//Vertex V0 = Vertex( 0, 1, 0);			
		//Vertex V1 = Vertex( 1, 0, 0);
		//Vertex V2 = Vertex(-1, 0, 0);
		//Vertex normal = (V1 - V0).CrossProduct(V2 - V1); // (V1-V0) x (V2-V1)
	

		//Sphere S(Vertex(0, 0, 70), 10, Color::Yellow);

		Shape* Shapes[3] = { &T1, &T2, &T3 };

		Vertex camera = Vertex(0, 0, 0); //beginning point


		for (int y = 0; y < 450; y++)
		{
			for (int x = 0; x < 800; x++)
			{
				Vertex pixel = Vertex(16 * x / 799.0F - 8, 4.5 - y * 9 / 449.0F, 10);// 2d to 3d transform point
				Vertex Rd = (pixel - camera).Normalize(); 
				Color c = TraceRayTri(camera, Rd, Shapes);
				surface->SetPixel(x, y, c);
			}
			pictureBox1->Refresh();
		}

		//Vertex Rd = Vertex(0, 0, 1);
		//Color c = TraceRay(camera, Rd, Shapes);

		DateTime endTime;
		endTime = endTime.Now;
		TimeSpan deltaTime = endTime - startTime;
		textBox1->Text = (Math::Round(100 * deltaTime.TotalSeconds) / 100.0F).ToString();

		DateTime date;
		String^ filename = date.Now.Year.ToString() + date.Now.Month.ToString() + date.Now.Day.ToString() +
			date.Now.Hour.ToString() + date.Now.Minute.ToString() + date.Now.Second.ToString() + ".jpg";
		    //surface->Save("image/" + filename);
	}
	private: System::Void createSpheres(System::Object^ sender, System::EventArgs^ e) {

		DateTime startTime;
		startTime = startTime.Now;

		Bitmap^ surface = gcnew Bitmap(800, 450);
		pictureBox1->Image = surface;

		Sphere S(Vertex(0, 0, 200), 75, Color::Orange);	

		Shape* Shapes[1] = { &S };

		Vertex camera = Vertex(0, 0, 0);				

		for (int y = 0; y < 450; y++)
		{
			for (int x = 0; x < 800; x++)
			{
				Vertex pixel = Vertex(16 * x / 799.0F - 8, 4.5 - y * 9 / 449.0F, 10);
				Vertex Rd = (pixel - camera).Normalize();
				Color c = TraceRaySphere(camera, Rd, Shapes);
				surface->SetPixel(x, y, c);
			}
			pictureBox1->Refresh();
		}

		//Vertex Rd = Vertex(0, 0.6, 0.8);
		//Color c = TraceRay(camera, Rd, Shapes);

		DateTime endTime;
		endTime = endTime.Now;
		TimeSpan deltaTime = endTime - startTime;
		textBox1->Text = (Math::Round(100 * deltaTime.TotalSeconds) / 100.0F).ToString();

		DateTime date;
		String^ filename = date.Now.Year.ToString() + date.Now.Month.ToString() + date.Now.Day.ToString() +
			date.Now.Hour.ToString() + date.Now.Minute.ToString() + date.Now.Second.ToString() + ".jpg";
		
	}
	};

#endif // !_MYFORM_H


