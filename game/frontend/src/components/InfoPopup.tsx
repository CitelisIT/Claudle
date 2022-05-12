import { Popover, Transition } from "@headlessui/react";
import { QuestionMarkCircleIcon, XIcon } from "@heroicons/react/outline";
import { Fragment } from "react";

export default function InfoPopup() {
  return (
    <Popover>
      <Popover.Button className="flex items-center justify-center">
        <QuestionMarkCircleIcon className="navbar__icon" />
      </Popover.Button>
      <Transition
        as={Fragment}
        enter="transform transition ease-in duration-100"
        enterFrom="opacity-0"
        enterTo="opacity-100"
        leave="transform transition ease-in duration-100"
        leaveFrom="opacity-100"
        leaveTo="opacity-0"
      >
        <Popover.Panel className="fixed flex flex-col items-center justify-center gap-4 p-4 bg-gray-900 border border-gray-600 rounded-lg shadow-2xl top-20 left-4 right-4 md:w-3/12">
          <div className="flex justify-between w-full itemns-center">
            <h2 className="text-base font-semibold text-gray-200 md:text-lg lg:text-xl">
              Comment jouer ?
            </h2>
            <Popover.Button>
              <XIcon className="w-6 h-6 text-gray-200 md:w-8 md:h-8" />
            </Popover.Button>
          </div>
          <div className="w-full border-t-2 border-gray-600"></div>
          <p className="text-base text-gray-200 md:text-lg lg:text-xl">
            Devinez le mot en un nombre limité d'essais !
          </p>
          <p className="text-base text-gray-200 md:text-lg lg:text-xl">
            Chaque essai doit être avec un mot valide.
            <br />
            Après chaque essai, les lettres seront colorées selon leur présence
            dans le mot.
            <br />
            <span className="text-green-600">Vert</span> correspond à une lettre
            au bon endroit, <span className="text-amber-400">Jaune</span> à une
            lettre présente dans le mot mais pas au bon endroit et{" "}
            <span className="text-gray-500">Gris</span> à une lettre inexistante
            dans le mot.
          </p>
        </Popover.Panel>
      </Transition>
    </Popover>
  );
}
