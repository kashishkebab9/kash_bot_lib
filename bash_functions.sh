
function test() {
  echo "Running Test on Binary: $1";
  $1;
  if [[$? == 0]]; then
    echo "$1 Suceeded!"
  else
    echo "$1 Failed!"
  fi




}
