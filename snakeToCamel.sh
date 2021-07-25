# for file in *; do
# SEARCH_FOLDER = /home/kaustav/Desktop/competitive-programming/GeeksForGeeks/* /home/kaustav/Desktop/competitive-programming/GeeksForGeeks/**/*
for file in *.cpp; do
    echo "Renaming name $file to "
    echo "$file" | sed -r 's/(^|_)([a-z])/\U\2/g'
    mv -v "$file" $(echo "$file" | sed -r 's/(^|_)([a-z])/\U\2/g')
    echo
done
