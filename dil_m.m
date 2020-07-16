function [I1]=dil_m(I,se)

%I = imread('text_gaps.tif');
%I(445:508,1:508)=false;
%I=true(10,10);
%figure,imshow(I);
[m,n]=size(I);
I1=false(m,n);
%se=true(3,3);
se=rflctn(se);
[sm,sn]=size(se);
p=fix(sm/2);
r=fix(sn/2);
J(1:m+2*p,1:n+2*r)=false;
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
        q=1;
        q1=J(i-p:i+p,j-r:j+r).*se;
        if(se==1)
            if(q1==0)
                q=0;
            end
        else
            q=0;
            for si=1:2*p+1;
                for sj=1:2*r+1;
                    if(se(si,sj)==true)
                        if(q1(si,sj)==true)
                            q=1;break;
                        end
                    end
                end
                if(q==1)
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
end