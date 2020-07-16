function [I1]=ero_m(I,se)

% I = imread('wirebond.tif');
%I=true(500,500);
% figure,imshow(I);
[m,n]=size(I);
I1=false(m,n);
%se=true(101,101);
[sm,sn]=size(se);
p=fix(sm/2);
r=fix(sn/2);
J(1:m+2*p,1:n+2*r)=true;
for i=1:m;
    for j=1:n;
        %if(i>p && i<m+p+1)
            %if(j>p && j<m+p+1)
                J(i+p,j+r)=I(i,j);
            %end 
        %end
    end
end
%figure,imshow(J);
for i=p+1:m+p;
    for j=r+1:n+r;
        q=0;
        q1=J(i-p:i+p,j-r:j+r).*se;
        if(se==1)
            if(q1==1)
                q=1;
            end
        else
            q=1;    
            for si=1:2*p+1;
                for sj=1:2*r+1;
                    if(se(si,sj)==true)
                       if(q1(si,sj)==false)
                        q=0;break;
                       end
                    end
                end
                if(q==0)
                   break;
                end
            end     
        end
        if(q==0)
           I1(i-p,j-r)=false;
        else
           I1(i-p,j-r)=true;
        end
    end
end
% figure,imshow(I1);
end