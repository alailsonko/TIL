import React, { useState, useEffect } from "react";
function UseEffectComponent() {
  const [value, setValue] = useState<number>(1);
  useEffect(() => {
   const timer = window.setInterval(() => {
      setValue((v) => v + 1);
    }, 1000);
    return () => window.clearInterval(timer)
  }, []);

  return (
    <div>
      <div>{value}</div>
    </div>
  );
}

export default UseEffectComponent;
