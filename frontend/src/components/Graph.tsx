import React from "react";

export default function Graph() {
  return (
    <div className="flex flex-col items-center justify-center">
      <div className="flex flex-col items-start justify-center gap-4 my-8 a -lg lg:text-xl">
        <div className="flex flex-row items-center justify-start gap-2">
          <span>1</span>
          <div className="py-1 pl-20 pr-2 text-right bg-green-600 rounded-sm">
            2
          </div>
        </div>
        <div className="flex flex-row items-center justify-start gap-2">
          <span>2</span>
          <div className="py-1 pl-8 pr-2 text-right bg-green-600 rounded-sm ">
            1
          </div>
        </div>
        <div className="flex flex-row items-center justify-start gap-2">
          <span>3</span>
          <div className="py-1 pl-64 pr-2 text-right bg-green-600 rounded-sm">
            7
          </div>
        </div>
        <div className="flex flex-row items-center justify-start gap-2">
          <span>4</span>
          <div className="py-1 pl-2 pr-2 text-right bg-gray-600 rounded-sm">
            0
          </div>
        </div>
      </div>
    </div>
  );
}
