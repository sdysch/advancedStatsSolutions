//root plotting histogram for times
void plot() {
	std::ifstream f1("absorbed_end.dat");// determine min and max times
	std::ifstream f2("absorbed.dat");
	Double_t min1, max1, min2, max2, sum1, sum2 = 0;
	Int_t entries1, entries2 = 0;
	Double_t time;

	while (!f1.eof()) {// read in data
		f1 >> time;
		if (time < min1) min1 = time;
		if (time > max1) max1 = time;
		sum1 += time;
		++entries1;
	}
	
	std::cout << "Mean end absorb time = " << (double) sum1 / entries1 << std::endl;

	while (!f2.eof()) {
		f2 >> time;
		if (time < min2) min2 = time;
		if (time > max2) max2 = time;
		sum2 += time;
		++entries2;
	}
	
	std::cout << "Mean end absorb time = " << (double) sum2 / entries2 << std::endl;	

	f1.close();
	f2.close();

	TH1D* h1 = new TH1D("Absorbtion at end", "Absorbtion at end", 50, min1, max1);// declare histograms
	TH1D* h2 = new TH1D("Absorbtion", "Absorbtion", 50, min2, max2);// declare histograms

	std::ifstream f1("absorbed_end.dat");
	std::ifstream f2("absorbed.dat");
	Double_t time;

	while (!f1.eof()) {// read in data
		f1 >> time;
		h1->Fill(time);
	}

	while (!f2.eof()) {
		f2 >> time;
		h2->Fill(time);
	}
	f1.close();
	f2.close();

	//canvases
	TCanvas *c1 = new TCanvas("c1","Absorbtion time @ end",200,10,700,500);
	h1->GetXaxis()->SetTitle("Absorption time");
	h1->GetYaxis()->SetTitle("Entries / 50");	
	h1->Draw();
	gStyle->SetOptStat(0);
	c1->SaveAs("Absorbtion_time_at_end.png");

	TCanvas *c2 = new TCanvas("c2","Absorbtion time",200,10,700,500);
	h2->GetXaxis()->SetTitle("Absorption time");
	h2->GetYaxis()->SetTitle("Entries / 50");	
	h2->Draw();
	gStyle->SetOptStat(0);
	c2->SaveAs("Absorbtion_time.png");	
}
