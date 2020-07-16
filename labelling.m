 close all;
 clear;
 I = imread('connected.jpg');
 J = rgb2gray(I);
 figure,imshow(J);
%function[J4]=labelling(J)
%J=imread('rgn_fill.tif');
[m,n]=size(J);
%converts image into binary image
% for q=0:7;
    t=dec2bin(2^7);
    l=length(t);
    if(l<8)
        k(1:8-l)=48;    
    end
    k(8-l+1:8)=t(1:l);
    k=k-48;
    for i=1:m;
     for j=1:n;
         x=J(i,j);
         y=dec2bin(x);
         l=length(y);
         if(l<8)
             p(1:8-l)=48;
         end
         p(8-l+1:8)=y(1:l);
         p=p-48;
         z=k&p;
         if(z==0)
            J1(i,j)=false;
         else
            J1(i,j)=true;
         end
     end
    end
    figure,imshow(J1);
%end
J2(m+2,n+2)=0;
J3(m+2,n+2)=0;
J4(m,n)=0;
lbl=0;
r=0;
% zero paddaing around image
for i=1:m+2;
    for j=1:n+2;
        if(i>1 && i<m+2)
            if(j>1 && j<n+2)
                J2(i,j)=J1(i-1,j-1);
            end
        end
    end
end
% labelling 1st pass
for i=2:m+1;
    for j=2:n+1;
        x=J2(i,j);
        if(x==1)
            if(J2(i-1,j)==0 && J2(i,j-1)==0)
                lbl=lbl+1;
                J3(i,j)=lbl;
            elseif(J2(i-1,j)==1 && J2(i,j-1)==1)
                if(J3(i-1,j)==J3(i,j-1))
                    J3(i,j)=J3(i-1,j);
                elseif(J3(i-1,j)<J3(i,j-1))
                    J3(i,j)=J3(i-1,j);
                    match=0;
                    for i1=1:r;
                        if(tbl(i1,1)==J3(i-1,j) && tbl(i1,2)==J3(i,j-1)) 
                           match=1; 
                           break;
                        end
                    end
                    if(match==0)
                        r=r+1;
                        tbl(r,1)=J3(i-1,j);
                        tbl(r,2)=J3(i,j-1);
                    end
                else
                    J3(i,j)=J3(i,j-1);
                    match=0;
                    for i1=1:r;
                        if(tbl(i1,1)==J3(i-1,j) && tbl(i1,2)==J3(i,j-1)) 
                           match=1; 
                           break;
                        end
                    end
                    if(match==0)
                        r=r+1;
                        tbl(r,1)=J3(i-1,j);
                        tbl(r,2)=J3(i,j-1);
                    end
                end
            else
                if(J2(i-1,j)==1 && J2(i,j-1)==0)
                    J3(i,j)=J3(i-1,j);
                else    
                    J3(i,j)=J3(i,j-1);
                end
            end
        end
    end
end
% labelling 2nd pass J4 final o/p array
for i=2:m+1;
    for j=2:n+1;
        x=J3(i,j);
        if(x~=0 && x~=1)
            for k=1:r;           
                if(tbl(r+1-k,2)==x)
                    x=tbl(r+1-k,1);
                end
            end
        end
        J4(i-1,j-1)=x;
    end
end
%end
figure,imagesc(J4); figure(gcf)