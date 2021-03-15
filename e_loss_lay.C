#include <iostream>
#include <fstream>

int e_loss_lay(){

				ifstream ifs20 ("e_loss_lay_20GeV.txt");
				ifstream ifs50 ("e_loss_lay_50GeV.txt");
				ifstream ifs100 ("e_loss_lay_100GeV.txt");
				ifstream ifs200 ("e_loss_lay_200GeV.txt");

				double a, b, c, d, e, f, g, h;

				TH1D* e_layer_20 = new TH1D("", "energy loss at each layer", 30, 36750, 38250);
				TH1D* e_layer_50 = new TH1D("", "energy loss at each layer", 30, 36750, 38250);
				TH1D* e_layer_100 = new TH1D("", "energy loss at each layer", 30, 36750, 38250);
				TH1D* e_layer_200 = new TH1D("", "energy loss at each layer", 30, 36750, 38250);

				while( ifs20 >> a >> b ){

								e_layer_20->Fill(a, b);

				}

				while( ifs50 >> c >> d ){

								e_layer_50->Fill(c, d);

				}
				
				while( ifs100 >> e >> f ){

								e_layer_100->Fill(e, f);

				}
				
				while( ifs200 >> g >> h ){

								e_layer_200->Fill(g, h);

				}

				TCanvas* c1 = new TCanvas("c1", "", 600, 600);

				e_layer_20->SetLineColor(kRed);
				e_layer_50->SetLineColor(kMagenta);
				e_layer_100->SetLineColor(kBlue);
				e_layer_200->SetLineColor(kGreen);

				e_layer_20->Sumw2(0);
				e_layer_50->Sumw2(0);
				e_layer_100->Sumw2(0);
				e_layer_200->Sumw2(0);

				c1->cd();
				e_layer_200->Draw();
				e_layer_100->Draw("sames");
				e_layer_50->Draw("sames");
				e_layer_20->Draw("sames");

				return 0;
}

