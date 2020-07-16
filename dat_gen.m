I = imread('new1.bmp');
 
fid = fopen('new1.dat','w+');
if(fid==-1)
    error('enable to open');
end
 
fprintf(fid,'1651 1 800 1 10000 \n');
[m,n]=size(I);
for i=1:m
    for j=0:(n/4)-1
        fprintf(fid,'0x%.2x%.2x%.2x%.2x \n',I(i,4*j+1),I(i,4*j+2),I(i,4*j+3),I(i,4*j+4));
    end
end
fclose(fid);
