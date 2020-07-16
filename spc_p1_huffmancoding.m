clc; 
close all; 
clear all;
A=imread('cameraman.tif');
[r,c]=size(A);
a1=max(A);
a=max(a1);
count=zeros(1,256);
for k=1:256
	count(1,k)=0;
	for i=1:r
		for j=1:c
			if(A(i,j)==k)
			count(1,k)=count(1,k)+1;
			end
		end
	end
end
%probability
p=zeros(1,256);
for i=1:256
	p(1,i)=count(1,i)/(r*c);
end
symbols = 1:256 ;					% Alphabet vector                               
[dict,avglen] = huffmandict(symbols,p);
k=1;
for i=1:r
	for j=1:c
		sig(1,k)=A(i,j);
		k=k+1;
	end
end
sig_encoded = huffmanenco(sig,dict);		%encoding
deco = huffmandeco(sig_encoded,dict); 		% Decode the encoded signal.
k=1;
for i=1:r
	for j=1:c
		A1(i,j)=sig(1,k);
        		k=k+1;
	end
end
imshow(A1);
