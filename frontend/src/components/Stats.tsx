import React from "react";

export default function Stats() {
  return (
    <section id="stats" className="flex items-center justify-center">
      <div className="flex flex-col items-center justify-center gap-4 text-gray-200 text-md md:text-lg lg:text-xl md:items-start">
        <div className="flex flex-col items-center justify-center md:flex-row">
          <div className="flex flex-col items-center justify-center gap-2 p-4">
            <span className="text-3xl font-semibold">10</span>
            <span className="font-light">Parties Jouées</span>
          </div>
          <div className="flex flex-col items-center justify-center gap-2 p-4">
            <span className="text-3xl font-semibold">100%</span>
            <span className="font-light">Parties Gagnées</span>
          </div>
          <div className="flex flex-col items-center justify-center gap-2 p-4">
            <span className="text-3xl font-semibold">10</span>
            <span className="font-light">Série</span>
          </div>
          <div className="flex flex-col items-center justify-center gap-2 p-4">
            <span className="text-3xl font-semibold">10</span>
            <span className="font-light">Meilleure Série</span>
          </div>
        </div>
      </div>
    </section>
  );
}
