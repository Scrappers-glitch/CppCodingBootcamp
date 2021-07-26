#**
#* Ccoffee Build tool, manual build, alpha-v1.
#* Custom Includsions for GTKmm cpp wrapper
#* dependencies '-I"/usr/include/glibmm-2.9.1/glib" -I"/usr/include/sigc++-2.0/sigc++" -I"/usr/include/giomm-2.4" -I"/usr/include/gtkmm-4.2.0/gtk"'
#*
#* @author pavl_g.
#*#
echo "Compiling the project"

#1) define work directory
workDir='/home/twisted/GradleProjects/CppCodingBootcamp'

#2) delete old build
oldbuild=(${workDir}'/build/.build/*')
for ((idx=0; idx < ${#oldbuild[@]}; idx++)); do
    rm ${oldbuild[$idx]}
done

##remove the dir
rmdir ${workDir}'/build/.build/'

#3) recreate a clean one to gather cpp files for compiling & linking
mkdir ${workDir}'/build/.build'

##attrs : dir to compile & sharedLib name
libs=('/home/twisted/GradleProjects/CppCodingBootcamp/src/libs/*')
main=('/home/twisted/GradleProjects/CppCodingBootcamp/src/main/*')

merge[0]=${libs}
merge[1]=${main}

#4) copy cpp files to a gather directory
for ((idx=0; idx < ${#merge[@]}; idx++)); do
##act on ${merge[$idx]}
    cp ${merge[$idx]} ${workDir}'/build/.build'
done

# 5) get the final String
final=${workDir}'/build/.build/*'

# 6) execute using g++ compiler against cpp code
##prepare exec names
sharedlib='shared'
executable='CppCodeCamp.exec'
# 7) compile files with inclusions
g++ -x c++ -I'/home/twisted/GradleProjects/CppCodingBootcamp/src/includes' -o ${sharedlib} ${final}
clang++ -x c++ -I'/home/twisted/GradleProjects/CppCodingBootcamp/src/includes' -o ${executable} ${final}
# 7) move files to output dir
##prepare dirs
builddir=${workDir}'/build/'
outputdir=${workDir}'/output/'
##moving files
mv ${builddir}${sharedlib} ${outputdir}${sharedlib}
mv ${builddir}${executable} ${outputdir}${executable}

echo "Successfully Compiled"
