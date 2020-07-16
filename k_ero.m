function[J]=k_ero(I,se,k)
J=I;
for i=1:k
    J=ero_m(J,se);
end
end