%clear;clc;close all;
% J=imread('lor22d.jpg');
% I=rgb2gray(J);
%I=imread('rgn_fill.tif');
function[J4]=label(J1)
% K=gry_to_bin(I,127);
% J1=simple_edgedec_bin(K);
[m n]=size(J1);
%K=simple_edgedec_bin(J);
%zero paddaing around image
J2(m+2,n+2)=false;
J3(m+2,n+2)=0;
lbl=0;r=0;
for i=1:m
    for j=1:n
        J2(i+1,j+1)=J1(i,j);
    end
end
% labelling 1st pass
for i=2:m+1;
    for j=2:n+1;
        x=J2(i,j);
        if(x==1)
            if(J2(i-1,j-1)==0 && J2(i-1,j)==0 && J2(i-1,j+1)==0 && J2(i,j-1)==0)
                lbl=lbl+1;
                J3(i,j)=lbl;
            elseif(J2(i-1,j-1)==1 && J2(i-1,j)==0 && J2(i-1,j+1)==0 && J2(i,j-1)==0)
                J3(i,j)=J3(i-1,j-1);
            elseif(J2(i-1,j-1)==0 && J2(i-1,j)==1 && J2(i-1,j+1)==0 && J2(i,j-1)==0)
                J3(i,j)=J3(i-1,j);
            elseif(J2(i-1,j-1)==0 && J2(i-1,j)==0 && J2(i-1,j+1)==1 && J2(i,j-1)==0)
                J3(i,j)=J3(i-1,j+1);
            elseif(J2(i-1,j-1)==0 && J2(i-1,j)==0 && J2(i-1,j+1)==0 && J2(i,j-1)==1)
                J3(i,j)=J3(i,j-1);
            elseif(J2(i-1,j-1)==1 && J2(i-1,j)==1 && J2(i-1,j+1)==0 && J2(i,j-1)==0)
                if(J3(i-1,j-1)~=J3(i-1,j))
                    match=0;
                        for i1=1:r;
                            if(tbl(i1,1)==J3(i-1,j-1) && tbl(i1,2)==J3(i-1,j)) 
                               match=1; 
                               break;
                            end
                        end
                        if(match==0)
                            r=r+1;
                            tbl(r,1)=J3(i-1,j-1);
                            tbl(r,2)=J3(i-1,j);
                        end
                        t=min(J3(i-1,j-1),J3(i-1,j));
                        J3(i-1,j-1)=t;J3(i-1,j)=t;
                end
                J3(i,j)=J3(i-1,j-1);
            elseif(J2(i-1,j-1)==1 && J2(i-1,j)==0 && J2(i-1,j+1)==1 && J2(i,j-1)==0)
               if(J3(i-1,j-1)~=J3(i-1,j+1))
                    match=0;
                        for i1=1:r;
                            if(tbl(i1,1)==J3(i-1,j-1) && tbl(i1,2)==J3(i-1,j+1)) 
                               match=1; 
                               break;
                            end
                        end
                        if(match==0)
                            r=r+1;
                            tbl(r,1)=J3(i-1,j-1);
                            tbl(r,2)=J3(i-1,j+1);
                        end
                        t=min(J3(i-1,j-1),J3(i-1,j+1));
                        J3(i-1,j-1)=t;J3(i-1,j+1)=t;
                end
                J3(i,j)=J3(i-1,j-1);
            elseif(J2(i-1,j-1)==1 && J2(i-1,j)==0 && J2(i-1,j+1)==0 && J2(i,j-1)==1)
               if(J3(i-1,j-1)~=J3(i,j-1))
                    match=0;
                        for i1=1:r;
                            if(tbl(i1,1)==J3(i-1,j-1) && tbl(i1,2)==J3(i,j-1)) 
                               match=1; 
                               break;
                            end
                        end
                        if(match==0)
                            r=r+1;
                            tbl(r,1)=J3(i-1,j-1);
                            tbl(r,2)=J3(i,j-1);
                        end
                        t=min(J3(i-1,j-1),J3(i,j-1));
                        J3(i-1,j-1)=t;J3(i,j-1)=t;
                end
                J3(i,j)=J3(i-1,j-1);
            elseif(J2(i-1,j-1)==0 && J2(i-1,j)==1 && J2(i-1,j+1)==1 && J2(i,j-1)==0)
                 if(J3(i-1,j+1)~=J3(i-1,j))
                    match=0;
                        for i1=1:r;
                            if(tbl(i1,1)==J3(i-1,j+1) && tbl(i1,2)==J3(i-1,j)) 
                               match=1; 
                               break;
                            end
                        end
                        if(match==0)
                            r=r+1;
                            tbl(r,2)=J3(i-1,j+1);
                            tbl(r,1)=J3(i-1,j);
                        end
                        t=min(J3(i-1,j+1),J3(i-1,j));
                        J3(i-1,j+1)=t;J3(i-1,j)=t;
                end
                J3(i,j)=J3(i-1,j+1);
            elseif(J2(i-1,j-1)==0 && J2(i-1,j)==1 && J2(i-1,j+1)==0 && J2(i,j-1)==1)
                 if(J3(i,j-1)~=J3(i-1,j))
                    match=0;
                        for i1=1:r;
                            if(tbl(i1,1)==J3(i,j-1) && tbl(i1,2)==J3(i-1,j)) 
                               match=1; 
                               break;
                            end
                        end
                        if(match==0)
                            r=r+1;
                            tbl(r,2)=J3(i,j-1);
                            tbl(r,1)=J3(i-1,j);
                        end
                        t=min(J3(i,j-1),J3(i-1,j));
                        J3(i,j-1)=t;J3(i-1,j)=t;
                end
                J3(i,j)=J3(i,j-1);
            elseif(J2(i-1,j-1)==0 && J2(i-1,j)==0 && J2(i-1,j+1)==1 && J2(i,j-1)==1)
                if(J3(i,j-1)~=J3(i-1,j+1))
                    match=0;
                        for i1=1:r;
                            if(tbl(i1,1)==J3(i,j-1) && tbl(i1,2)==J3(i-1,j+1)) 
                               match=1; 
                               break;
                            end
                        end
                        if(match==0)
                            r=r+1;
                            tbl(r,2)=J3(i,j-1);
                            tbl(r,1)=J3(i-1,j+1);
                        end
                        t=min(J3(i,j-1),J3(i-1,j+1));
                        J3(i,j-1)=t;J3(i-1,j+1)=t;
                end
                J3(i,j)=J3(i,j-1);
            elseif(J2(i-1,j-1)==0 && J2(i-1,j)==1 && J2(i-1,j+1)==1 && J2(i,j-1)==1)
                t1=[J3(i-1,j),J3(i-1,j+1),J3(i,j-1)];t=min(t1);
                J3(i,j)=t;J3(i-1,j)=t;J3(i-1,j+1)=t;J3(i,j-1)=t;
            elseif(J2(i-1,j-1)==1 && J2(i-1,j)==0 && J2(i-1,j+1)==1 && J2(i,j-1)==1)
                t1=[J3(i-1,j-1),J3(i-1,j+1),J3(i,j-1)];t=min(t1);
                J3(i,j)=t;J3(i-1,j-1)=t;J3(i-1,j+1)=t;J3(i,j-1)=t;
            elseif(J2(i-1,j-1)==1 && J2(i-1,j)==1 && J2(i-1,j+1)==0 && J2(i,j-1)==1)
                t1=[J3(i-1,j-1),J3(i-1,j),J3(i,j-1)];t=min(t1);
                J3(i,j)=t;J3(i-1,j-1)=t;J3(i-1,j)=t;J3(i,j-1)=t;
            elseif(J2(i-1,j-1)==1 && J2(i-1,j)==1 && J2(i-1,j+1)==1 && J2(i,j-1)==0)
                t1=[J3(i-1,j-1),J3(i-1,j),J3(i-1,j+1)];t=min(t1);
                J3(i,j)=t;J3(i-1,j-1)=t;J3(i-1,j)=t;J3(i-1,j+1)=t;
            elseif(J2(i-1,j-1)==1 && J2(i-1,j)==1 && J2(i-1,j+1)==1 && J2(i,j-1)==1)
                t1=[J3(i-1,j-1),J3(i-1,j),J3(i-1,j+1),J3(i,j-1)];t=min(t1);
                J3(i,j)=t;J3(i-1,j-1)=t;J3(i-1,j)=t;J3(i-1,j+1)=t;J3(i,j-1)=t;
            end
        end
    end
end
%second pass
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
end
% figure,imshow(J1);
% figure,imshow(J2);
% figure,imshow(J3);
% figure,imagesc(J4); figure(gcf)