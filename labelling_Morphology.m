clear;clc;close all;
I=imread('chickenfilet.tif');
%I1=rgb2gray(I);
J=gry_to_bin(I,203);
b(1:5,1:5)=true;
K=ero_m(J,b);
[m n]=size(K);
N(1:m,1:n)=0;
L(1:m,1:n)=0;
lbl=0;r=0;
%K=cplmnt(J);
% L=label(J);
% [N,p]=hole_points(L,1000);
for i=1:m
    for j=1:n
        if(L(i,j)==0)
            if(K(i,j)==1)
%                 q=0;
%                 for i1=1:r
%                     if(tbl(1,i1)==L(i,j))
%                         q=1;break;
%                     end
%                 end
%                if(q==0)
                    N(i,j)=true;
                    while(1)
                      M=N;  
                      N=dil_m(N,b);
                      N=intersection(N,K);
                      %figure,imshow(N);
                      if(N==M)
                          break;
                      end
                    end
                    %figure,imshow(N);
                    lbl=lbl+1;
                    r=r+1;c=0;
                    for i2=1:m
                        for j2=1:n
                            if(N(i2,j2)==1)
                                L(i2,j2)=lbl;c=c+1;
                            end
                        end
                    end
                    tbl(r,1)=lbl;tbl(r,2)=c;
                    N(1:m,1:n)=0;
%                    tbl(1,r)=lbl;
                %end
           end
        end
    end
end
%O=union(N,J);
figure,imshow(I);
figure,imshow(J);
figure,imshow(K);
figure,imagesc(L); figure(gcf)