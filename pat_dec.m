% clear;close all;clc;
% I=imread('convex.tif');
% se=[1,2,2;1,0,2;1,2,2];
function[I1]=pat_dec(I,se) 
[m,n]=size(I);
I1=false(m,n);
[sm,sn]=size(se);
p=fix(sm/2);
r=fix(sn/2);
J(m+2*p,n+2*r)=true;
for i=1:m;
    for j=1:n;
        J(i+p,j+r)=I(i,j);
    end
end
for i=p+1:m+p;
    for j=r+1:n+r;
        q=1;
        q1=J(i-p:i+p,j-r:j+r);
            for si=1:2*p+1;
                for sj=1:2*r+1;
                    if(se(si,sj)==1)
                       if(q1(si,sj)==false)
                        q=0;break;
                       end
                    elseif(se(si,sj)==0)
                       if(q1(si,sj)==true)
                        q=0;break;
                       end
                    end
                end
                if(q==0)
                   break;
                end
            end     
        
        if(q==1)
           I1(i-p,j-r)=true;
%         else
%            I1(i-p,j-r)=true;
        end
    end
end
% figure,imshow(I1);
% figure,imshow(I);
end
